#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
//#include <vector>

// milliseconds between render updates
// decides how often ProcessControl() is called
// and how often controls are read and redrawn
// update freq (UF) will be max 1/(1000 - DWINDOW_FRAME_MS)
// this means UI latency will be >= DWINDOW_FRAME_MS
// so a value of 10 gives UF 1/100 and a latency of 10 ms 
#define DWINDOW_FRAME_MS 10

// max # of controls (avoid dynami structures due to performance)
#define DWINDOW_CTRLS_MAX 32

// LayOut
// Vertical, Horizontal
// Small, Medium, Large
#define DWINDOW_LO_HL 400
#define DWINDOW_LO_HM 150
#define DWINDOW_LO_HS 50
#define DWINDOW_LO_VL 400
#define DWINDOW_LO_VM 150
#define DWINDOW_LO_VS 50
// Spacer
#define DWINDOW_LO_V_ 25
#define DWINDOW_LO_H_ 25

#define DCTRL_ON 1
#define DCTRL_OFF 0

class DControl;

class DWindow
{
public:

  DWindow();
  ~DWindow();
  void Setup();
  void Render();
  bool Process(const SDL_Event* event);
  void AddControl(DControl* control);
  bool Event();
  TTF_Font* GetFont();
  SDL_Renderer* GetRenderer();
  SDL_Rect* GetScreen();
  int GetWidth();
  int GetHeight();

private:
  SDL_Window* window_ = NULL;
  SDL_Rect screen_ = {0, 0, 640, 640};
  SDL_Renderer* renderer_ = NULL;
  TTF_Font* font_ = NULL;

  //std::vector<DControl*> controls_;
  DControl *controls_[DWINDOW_CTRLS_MAX];
};

class DControl
{
public:

  enum ControlType
  {
      VERTICAL,
      HORIZONTAL,
      CHECKBOX,
      ACTION,
      MATRIX,
  };

  struct Config
  {
    uint8_t id;
    DControl::ControlType type;
    std::string text;
    const SDL_Rect* pos;
    int min;
    int max;
    int value;
    DWindow* window;
  };

  DControl();
  ~DControl();
  void Init(const Config&);
  void Exit();
  void Draw();
  bool Process(const SDL_Event* event);
  uint8_t GetId();
  bool GetChange(u_int16_t *);

private:
  void RectOffset_(SDL_Rect* r, int x, int y);
  bool RectContains_(SDL_Rect* r, SDL_Point* p);

  DControl::ControlType type_;
  std::string text_;
  SDL_Rect pos_; // global bounding box
  uint16_t min_, max_, value_;

  uint8_t id_;
  DWindow* window_;
  SDL_Renderer* renderer_;
  TTF_Font* font_;
  SDL_Rect screen_;
  SDL_Texture* texture_ = NULL;
  SDL_Rect texture_rect_;
  SDL_Point touch_;

  // matrix data
  uint16_t *m_data_ = NULL;

  //uint64_t tlast_ = SDL_GetTicks64();
  bool changed_ = false;
  bool state_ = false;
};