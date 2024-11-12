#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "dwindow.h"

/*

  Class: DWindow

*/

DWindow::DWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL Error: %s\n", SDL_GetError());
    }
}

DWindow::~DWindow()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    TTF_CloseFont(font_);
    TTF_Quit();
    SDL_Quit();
}

void DWindow::Setup()
{
    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) == 0)
    {
        screen_.w = displayMode.w;
        screen_.h = displayMode.h;
    }

    std::cout << "DWindow " << screen_.w << ", " << screen_.h << "\n";

    window_ = SDL_CreateWindow(
        "DCube",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        screen_.w, screen_.h,
        SDL_WINDOW_FULLSCREEN);

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == NULL)
    {
        std::cout << "Error CreateRenderer(): " << SDL_GetError() << std::endl;
    }

    if (TTF_Init() < 0)
    {
        std::cout << "Error TTF_Init: " << TTF_GetError() << std::endl;
    }

    // /usr/share/fonts/truetype/noto/NotoMono-Regular.ttf
    font_ = TTF_OpenFont("/usr/share/fonts/truetype/noto/NotoMono-Regular.ttf", 24);
    if (!font_)
    {
        std::cout << "Error OpenFont: " << TTF_GetError() << std::endl;
    }

    for (uint8_t i = 0; i < DWINDOW_CTRLS_MAX; i++)
    {
        controls_[i] = NULL;
    }
}

void DWindow::AddControl(DControl *control)
{
    // controls_.push_back(control);
    uint8_t id = control->GetId();
    if (id < DWINDOW_CTRLS_MAX)
    {
        controls_[id] = control;
    }
}

void DWindow::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0x10, 0x10, 0x10, 0xFF);

    // clear screen
    SDL_RenderClear(renderer_);

    // Render controls
    /*
    for (const auto control : controls_)
    {
      control->Draw();
    }
    */
    for (uint8_t i = 0; i < DWINDOW_CTRLS_MAX; i++)
    {
        if (controls_[i] != NULL)
        {
            controls_[i]->Draw();
        }
    }

    // update screen
    SDL_RenderPresent(renderer_);
}

bool DWindow::Process(const SDL_Event *event)
{
    bool processed = false;
    if ((event->type == SDL_FINGERDOWN) ||
        (event->type == SDL_FINGERMOTION) ||
        (event->type == SDL_FINGERUP))
    {
        for (uint8_t i = 0; i < DWINDOW_CTRLS_MAX; i++)
        {
            if (controls_[i] != NULL)
            {
                processed |= controls_[i]->Process(event);
            }
        }
        /*
        for (const auto control : controls_)
        {
          processed |= control->Process(event);
        }
        */
    }

    return processed;
}

bool DWindow::Event()
{
    bool done = false;

    SDL_Event event;

    // SDL update and event handling
    auto time = SDL_GetTicks();
    while (SDL_PollEvent(&event))
    {
        // system
        if (event.type == SDL_QUIT)
        {
            done = true;
        }
        // event handling
        Process(&event);
    }

    // update/draw window
    Render();

    if ((SDL_GetTicks() - time) < DWINDOW_FRAME_MS)
    {
        SDL_Delay(DWINDOW_FRAME_MS);
    }

    return done;
}

TTF_Font *DWindow::GetFont()
{
    return font_;
}

SDL_Renderer *DWindow::GetRenderer()
{
    return renderer_;
}

SDL_Rect *DWindow::GetScreen()
{
    return &screen_;
}

int DWindow::GetWidth()
{
    return screen_.w;
}

int DWindow::GetHeight()
{
    return screen_.h;
}

/*

  Class: DControl

*/

#define DCONTROL_TIMEOUT 100

DControl::DControl()
{
}

DControl::~DControl()
{
}

void DControl::Init(const Config& config)
{
    id_ = config.id; // must be unique
    type_ = config.type;
    text_ = config.text;
    pos_.x = config.pos->x;
    pos_.y = config.pos->y;
    pos_.w = config.pos->w;
    pos_.h = config.pos->h;
    min_ = config.min;
    max_ = config.max;
    value_ = config.value;
    window_ = config.window;

    if (type_ == DControl::MATRIX)
    {
        m_data_ = new uint16_t[(min_ * max_)];
        for (auto i = 0; i < (min_ * max_); i++)
        {
            m_data_[i] = DCTRL_OFF;
        }
    }
    renderer_ = window_->GetRenderer();
    font_ = window_->GetFont();

    // texture title/value
    SDL_Color color = {240, 240, 240, 255};
    SDL_Surface *TextSurface{TTF_RenderUTF8_Solid(font_, text_.c_str(), color)};
    texture_ = SDL_CreateTextureFromSurface(renderer_, TextSurface);
    texture_rect_.x = 0;
    texture_rect_.y = 0;
    texture_rect_.w = TextSurface->w;
    texture_rect_.h = TextSurface->h;
    SDL_FreeSurface(TextSurface);

    changed_ = false;
}

void DControl::Exit()
{
    SDL_DestroyTexture(texture_);
    texture_ = NULL;
    if (m_data_)
        delete [] m_data_;
}

void DControl::Draw()
{
    // setup
    SDL_Rect r;
    int bar;
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

    // bounding box
    SDL_RenderDrawRect(renderer_, &pos_);

    // update controls with timeout
    /*
    if (type_  == DControl::ACTION)
    {
      if (value_ == 1)
      {
      if (SDL_GetTicks64() - tlast_ > DCONTROL_TIMEOUT)
        {
          tlast_ = SDL_GetTicks64();
          value_ = 0;
        }
      }
    }
    */

    // value indicator
    switch (type_)
    {
    case DControl::VERTICAL:
        bar = ((float)value_ / (max_ - min_)) * (pos_.h);
        r.x = pos_.x;
        r.y = pos_.y + pos_.h - bar;
        r.h = 2;
        r.w = pos_.w;
        SDL_RenderDrawRect(renderer_, &r);
        break;

    case DControl::HORIZONTAL:
        bar = ((float)value_ / (max_ - min_)) * (pos_.w);
        r.x = pos_.x + bar;
        r.y = pos_.y;
        r.h = pos_.h;
        r.w = 2;
        SDL_RenderDrawRect(renderer_, &r);
        break;

    case DControl::CHECKBOX:
        if (value_ > 0)
        {
            SDL_RenderDrawLine(renderer_, pos_.x, pos_.y, pos_.x + pos_.w, pos_.y + pos_.h);
            SDL_RenderDrawLine(renderer_, pos_.x + pos_.w, pos_.y, pos_.x, pos_.y + pos_.h);
        }
        break;

    case DControl::ACTION:
        r.x = pos_.x + pos_.w / 4;
        r.y = pos_.y + pos_.h / 4;
        r.h = pos_.h / 2;
        r.w = pos_.w / 2;
        if (value_ == DCTRL_ON)
        {
            SDL_RenderFillRect(renderer_, &r);
        }
        else
        {
            SDL_RenderDrawRect(renderer_, &r);
        }
        break;

    case DControl::MATRIX:
        {
        // bounding box already drawn
        // min_ - # steps horiz
        // max_ - # steps vert
        uint16_t size_h = pos_.w / min_;
        uint16_t size_v = pos_.h / max_;
        // vertical lines
        for (uint16_t i = 1; i < min_; i++)
        {
            
            SDL_RenderDrawLine(renderer_, pos_.x + i * size_h,
                                            pos_.y,
                                            pos_.x + i * size_h,
                                            pos_.y + pos_.h);
        }
        // horiz lines
        for (uint16_t i = 1; i < max_; i++)
        {
            SDL_RenderDrawLine(renderer_, pos_.x,
                                            pos_.y + i * size_v,
                                            pos_.x + pos_.w,
                                            pos_.y + i * size_v);
        }
        for(auto i = 0; i < (min_ * max_); i++)
        {
            if (m_data_[i] == DCTRL_ON)
            {
                auto m_row = i / min_;
                auto m_col = i - (m_row * min_);
                {
                    r.x = pos_.x + m_col * size_h;
                    r.y = pos_.y + m_row * size_v;
                    r.w = size_h;
                    r.h = size_v;
                    SDL_RenderFillRect(renderer_, &r);
                }
            }
        }
        }
        break;

    default:
        break;
    }

    // render name
    r = texture_rect_;
    RectOffset_(&r, pos_.x, pos_.y);
    SDL_RenderCopy(renderer_, texture_, &texture_rect_, &r);

    // render value
    SDL_Color color = {240, 240, 240, 255};
    std::string s = std::to_string(value_);
    SDL_Surface *TextSurface{TTF_RenderUTF8_Solid(font_, s.c_str(), color)};
    SDL_Texture *vt_ = NULL;
    vt_ = SDL_CreateTextureFromSurface(renderer_, TextSurface);
    r.x = 0;
    r.y = 0;
    r.w = TextSurface->w;
    r.h = TextSurface->h;
    SDL_FreeSurface(TextSurface);
    RectOffset_(&r, pos_.x, pos_.y + pos_.h - 30);
    SDL_RenderCopy(renderer_, vt_, &texture_rect_, &r);
    SDL_DestroyTexture(vt_);
}

bool DControl::Process(const SDL_Event *event)
{
    int w = window_->GetWidth();
    int h = window_->GetHeight();

    bool processed = false;
    if (event->type == SDL_FINGERDOWN)
    {
        touch_.x = event->tfinger.x * w;
        touch_.y = event->tfinger.y * h;
        processed = true;
    }
    else if (event->type == SDL_FINGERMOTION)
    {
        touch_.x = event->tfinger.x * w;
        touch_.y = event->tfinger.y * h;
        processed = true;
    }
    else if (event->type == SDL_FINGERUP)
    {
        touch_.x = event->tfinger.x * w;
        touch_.y = event->tfinger.y * h;
        processed = true;
    }

    if (processed)
    {
        // std::cout << gTouchLocation.x << ", " << gTouchLocation.y << std::endl;
        // rect_.x = touch_.x;
        // rect_.y = touch_.y;
        processed = RectContains_(&pos_, &touch_);
        if (processed)
        {
            changed_ = true;

            switch (type_)
            {
            case DControl::VERTICAL:
                value_ = ((float)(pos_.h - (touch_.y - pos_.y)) / (pos_.h)) * (max_ - min_);
                break;

            case DControl::HORIZONTAL:
                value_ = ((float)(touch_.x - pos_.x) / (pos_.w)) * (max_ - min_);
                break;

            case DControl::CHECKBOX:
                if (event->type == SDL_FINGERDOWN)
                {
                    if (value_ == 0)
                    {
                        value_ = 1;
                    }
                    else if (value_ == 1)
                    {
                        value_ = 0;
                    }
                }
                break;

            case DControl::ACTION:
                if (event->type == SDL_FINGERDOWN)
                {
                    if (value_ == DCTRL_OFF)
                    {
                        value_ = DCTRL_ON;
                    }
                }
                else if (event->type == SDL_FINGERUP)
                {
                    if (value_ == DCTRL_ON)
                    {
                        value_ = DCTRL_OFF;
                    }
                }
                break;

            case DControl::MATRIX:
            {
                // min_ - # steps horiz
                // max_ - # steps vert
                uint16_t size_h = pos_.w / min_;
                uint16_t size_v = pos_.h / max_;

                uint16_t m_h = (touch_.x - pos_.x) / size_h;
                uint16_t m_v = (touch_.y - pos_.y) / size_v;

                value_ = m_h + m_v * min_;
                if (event->type == SDL_FINGERDOWN)
                {
                    if (m_data_[value_] == DCTRL_OFF)
                    {
                        m_data_[value_] = DCTRL_ON;
                    }
                    else if (m_data_[value_] == DCTRL_ON)
                    {
                        m_data_[value_] = DCTRL_OFF;
                    }
                }

            }
            break;

            default:
                break;
            }
        }
    }

    return processed;
}

// offset (move) rectangle with x and y
void DControl::RectOffset_(SDL_Rect *r, int x, int y)
{
    r->x += x;
    r->y += y;
}

// return true if rectangle contains point
bool DControl::RectContains_(SDL_Rect *r, SDL_Point *p)
{
    if ((p->x > r->x) && (p->x < (r->x + r->w)) && (p->y > r->y) && (p->y < (r->y + r->h)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint8_t DControl::GetId()
{
    return (id_);
}

bool DControl::GetChange(uint16_t *value)
{
    bool changed = changed_;

    if (changed_)
    {
        changed_ = false;
        *value = value_;
    }

    return (changed);
}