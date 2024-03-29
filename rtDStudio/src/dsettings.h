#pragma once

#include "libs/tinyxml.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/// from ofutils.h/openFrameworks
/// \section String Conversion
/// \brief Convert a value to a string.
///
/// ofToString does its best to convert any value to a string. If the data type
/// implements a stream << operator, then it will be converted.
///
/// Example:
/// ~~~~{.cpp}
///    std::string str = "framerate is ";
///    str += ofToString(ofGetFrameRate()) + " fps";
///    // The string now contains something like "framerate is 60 fps".
/// ~~~~
///
/// \tparam T The data type of the value to convert to a string.
/// \param value The value to convert to a string.
/// \returns A string representing the value or an empty string on failure.
template <class T>
std::string ofToString(const T& value){
	std::ostringstream out;
	out << value;
	return out.str();
}
/// \brief Convert a string to a given data type.
/// \tparam T The return type.
/// \param value The string value to convert to a give type.
/// \returns the string converted to the type.
template<typename T>
T ofTo(const std::string & str){
	T x;
	std::istringstream cur(str);
	cur >> x;
	return x;
}



// DXMLSettings
class DXMLSettings
{

    public:
        DXMLSettings()
        {
        }
        ~DXMLSettings()
        {
        }

        void setValue(const std::string& tag, int value);
        void setValue(const std::string& tag, float value);
        void setValue(const std::string& tag, const std::string& value);
        int getValue(const std::string& tag, int defaultValue);
        float getValue(const std::string& tag, float defaultValue);
        std::string getValue(const std::string& tag, const std::string& defaultValue);
        
        void loadInit(const std::string& fileName);
        void loadExit();
        void saveInit(const std::string& fileName);
        void saveExit();
    
    private:
        std::string fileName_;
    	TiXmlDocument *doc_;  
	TiXmlElement *setting_;
        TiXmlElement *root_;
};

// static methods - no need to instantiate

class DSettings
{

	public:

    enum DSoundType
    {
        DSYNTHSUB,
        DSYNTHFM,
        DSYNTHVAR,
        DSAMPLER,
        DRUM
        // more to come: mixer, fx, seq etc
    };

    enum DSoundSubType
    {
        NONE,
        DBASS,
        DSNARE,
        DHIHAT,
        DCLAP,
        DCYMBAL,
        DDRUM
    };

    DSettings() {}
    ~DSettings() {}
    
    void static TestWrite();  
    void static TestRead();    
    void static SaveSetting(DSoundType type, DSoundSubType subtype, std::string file_name, void *config);
    void static LoadSetting(DSoundType type, DSoundSubType subtype, std::string file_name, void *config);

private:

    std::string static VecToStr(std::vector<float> vec);
    std::vector<float> static StrToVec(std::string str);
};
