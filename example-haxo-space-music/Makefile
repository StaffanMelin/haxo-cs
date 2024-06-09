MAKEFILE      = Makefile
EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -D__LINUX_ALSA__
CFLAGS        = -pipe -O2 -Wall -Wextra -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -Wextra -fPIC $(DEFINES)
INCPATH       = -I. \
				-I../rtDStudio/src \
				-I../rtDStudio/src/libs \
				-I../rtDaisySP/src/Control \
				-I../rtDaisySP/src/Drums \
				-I../rtDaisySP/src/Dynamics \
				-I../rtDaisySP/src/Effects \
				-I../rtDaisySP/src/Filters \
				-I../rtDaisySP/src/Noise \
				-I../rtDaisySP/src/PhysicalModeling \
				-I../rtDaisySP/src/Synthesis \
				-I../rtDaisySP/src/Utility
LINK          = g++
LFLAGS        = 
#LIBS          = $(SUBLIBS) -lpthread -lsndfile -lasound -lgpiod -li2c
LIBS          = $(SUBLIBS) -lpthread -lsndfile -lasound -lgpiod -li2c

####### Files
SOURCES   = main.cpp \
			rtApp.cpp \
			../rtaudio/RtAudio.cpp \
			$(wildcard ../rtDStudio/src/libs/*.cpp) \
			$(wildcard ../rtDStudio/src/*.cpp) \
			$(wildcard ../rtDaisySP/src/Control/*.cpp) \
			$(wildcard ../rtDaisySP/src/Drums/*.cpp) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.cpp) \
			$(wildcard ../rtDaisySP/src/Effects/*.cpp) \
			$(wildcard ../rtDaisySP/src/Filters/*.cpp) \
			$(wildcard ../rtDaisySP/src/Noise/*.cpp) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.cpp) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.cpp) \
			$(wildcard ../rtDaisySP/src/Utility/*.cpp)

ITEMS = $(basename $(notdir $(SOURCES)))
OBJECTS  = $(foreach item,$(ITEMS),$(item).o)
OBJECTS_PATH  = $(foreach item,$(ITEMS),./bin/$(item).o)
$(info    TEST0 is $(OBJECTS)) 
$(info    TEST1 is $(OBJECTS_PATH)) 

TARGET    = rtDStudioExample

#first: all
####### Build rules

rtDStudioDemo: $(OBJECTS) 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS_PATH) $(OBJCOMP) $(LIBS)

all: Makefile rtDStudioExample

####### Compile

main.o: 	main.cpp  \
			main.h \
			rtApp.h \
			../rtaudio/RtAudio.h \
			$(wildcard ../rtDStudio/src/*.h) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/main.o main.cpp

rtApp.o: 	rtApp.cpp \
			rtApp.h \
			$(wildcard ../rtDStudio/src/*.h) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/rtApp.o rtApp.cpp

RtAudio.o: 	../rtaudio/RtAudio.cpp \
			../rtaudio/RtAudio.h \
			../rtDStudio/src/dsound.h \
			../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/RtAudio.o ../rtaudio/RtAudio.cpp

tinyxml.o: ../rtDStudio/src/libs/tinyxml.cpp \
			../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tinyxml.o ../rtDStudio/src/libs/tinyxml.cpp

tinyxmlerror.o: ../rtDStudio/src/libs/tinyxmlerror.cpp \
				../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tinyxmlerror.o ../rtDStudio/src/libs/tinyxmlerror.cpp

tinyxmlparser.o: ../rtDStudio/src/libs/tinyxmlparser.cpp \
				../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tinyxmlparser.o ../rtDStudio/src/libs/tinyxmlparser.cpp

dbass.o: 	../rtDStudio/src/dbass.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dbass.o ../rtDStudio/src/dbass.cpp

dclap.o: ../rtDStudio/src/dclap.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dclap.o ../rtDStudio/src/dclap.cpp

dcymbal.o: ../rtDStudio/src/dcymbal.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dcymbal.o ../rtDStudio/src/dcymbal.cpp

ddrum.o: 	../rtDStudio/src/ddrum.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/ddrum.o ../rtDStudio/src/ddrum.cpp

dfx.o: 		../rtDStudio/src/dfx.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dfx.o ../rtDStudio/src/dfx.cpp

dgen.o: 	../rtDStudio/src/dgen.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dgen.o ../rtDStudio/src/dgen.cpp

dhaxo.o: 	../rtDStudio/src/dgen.cpp \
			../rtDStudio/src/dstudio.h \
			../rtDStudio/src/dhaxo.h \
			../rtDStudio/src/dhaxo.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dhaxo.o ../rtDStudio/src/dhaxo.cpp

dhihat.o: 	../rtDStudio/src/dhihat.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dhihat.o ../rtDStudio/src/dhihat.cpp

dmixer.o: 	../rtDStudio/src/dmixer.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dmixer.o ../rtDStudio/src/dmixer.cpp

dsampler.o: ../rtDStudio/src/dsampler.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsampler.o ../rtDStudio/src/dsampler.cpp

dseqmidi.o: ../rtDStudio/src/dseqmidi.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dseqmidi.o ../rtDStudio/src/dseqmidi.cpp

dseqperm.o: ../rtDStudio/src/dseqperm.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dseqperm.o ../rtDStudio/src/dseqperm.cpp

dsettings.o: ../rtDStudio/src/dsettings.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDStudio/src/libs/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsettings.o ../rtDStudio/src/dsettings.cpp

dsm.o: 		../rtDStudio/src/dsm.cpp \
			../rtDStudio/src/dstudio.h \
			../rtDStudio/src/dsm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsm.o ../rtDStudio/src/dsm.cpp

dsnare.o: 	../rtDStudio/src/dsnare.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsnare.o ../rtDStudio/src/dsnare.cpp

dsound.o: 	../rtDStudio/src/dsound.cpp \
			../rtDStudio/src/dsound.h \
			../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsound.o ../rtDStudio/src/dsound.cpp

dsplit.o: 	../rtDStudio/src/dsplit.cpp \
			../rtDStudio/src/dstudio.h \
			../rtDStudio/src/dsplit.h \
			../rtDStudio/src/dsound.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsplit.o ../rtDStudio/src/dsplit.cpp

dstudio.o: ../rtDStudio/src/dstudio.cpp \
			../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dstudio.o ../rtDStudio/src/dstudio.cpp

dsynth.o: ../rtDStudio/src/dsynth.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsynth.o ../rtDStudio/src/dsynth.cpp

dsynthfm.o: ../rtDStudio/src/dsynthfm.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsynthfm.o ../rtDStudio/src/dsynthfm.cpp

dsynthsub.o: ../rtDStudio/src/dsynthsub.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsynthsub.o ../rtDStudio/src/dsynthsub.cpp

dsynthvar.o: ../rtDStudio/src/dsynthvar.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dsynthvar.o ../rtDStudio/src/dsynthvar.cpp

tclap.o: 	../rtDStudio/src/tclap.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tclap.o ../rtDStudio/src/tclap.cpp

tcymbal.o: ../rtDStudio/src/tcymbal.cpp \
			$(wildcard ../rtDStudio/src/*) \
			$(wildcard ../rtDaisySP/src/Control/*.h) \
			$(wildcard ../rtDaisySP/src/Drums/*.h) \
			$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
			$(wildcard ../rtDaisySP/src/Effects/*.h) \
			$(wildcard ../rtDaisySP/src/Filters/*.h) \
			$(wildcard ../rtDaisySP/src/Noise/*.h) \
			$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
			$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
			$(wildcard ../rtDaisySP/src/Utility/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tcymbal.o ../rtDStudio/src/tcymbal.cpp

tdrum.o: 	../rtDStudio/src/tdrum.cpp \
			../rtDStudio/src/tdrum.h \
			../rtDaisySP/src/Control/adenv.h \
			../rtDaisySP/src/Synthesis/oscillator.h \
			../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tdrum.o ../rtDStudio/src/tdrum.cpp

adenv.o: 	../rtDaisySP/src/Control/adenv.cpp \
			../rtDaisySP/src/Control/adenv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/adenv.o ../rtDaisySP/src/Control/adenv.cpp

adsr.o: 	../rtDaisySP/src/Control/adsr.cpp \
			../rtDaisySP/src/Control/adsr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/adsr.o ../rtDaisySP/src/Control/adsr.cpp

line.o: 	../rtDaisySP/src/Control/line.cpp \
			../rtDaisySP/src/Control/line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/line.o ../rtDaisySP/src/Control/line.cpp

phasor.o: 	../rtDaisySP/src/Control/phasor.cpp \
			../rtDaisySP/src/Control/phasor.h \
			../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/phasor.o ../rtDaisySP/src/Control/phasor.cpp

analogbassdrum.o: ../rtDaisySP/src/Drums/analogbassdrum.cpp \
			../rtDaisySP/src/Utility/dsp.h \
			../rtDaisySP/src/Drums/analogbassdrum.h \
			../rtDaisySP/src/Synthesis/oscillator.h \
			../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/analogbassdrum.o ../rtDaisySP/src/Drums/analogbassdrum.cpp

analogsnaredrum.o: ../rtDaisySP/src/Drums/analogsnaredrum.cpp \
			../rtDaisySP/src/Utility/dsp.h \
			../rtDaisySP/src/Drums/analogsnaredrum.h \
			../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/analogsnaredrum.o ../rtDaisySP/src/Drums/analogsnaredrum.cpp

hihat.o: 	../rtDaisySP/src/Drums/hihat.cpp \
			../rtDaisySP/src/Utility/dsp.h \
			../rtDaisySP/src/Drums/hihat.h \
			../rtDaisySP/src/Filters/svf.h \
			../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/hihat.o ../rtDaisySP/src/Drums/hihat.cpp

synthbassdrum.o: ../rtDaisySP/src/Drums/synthbassdrum.cpp \
			../rtDaisySP/src/Drums/synthbassdrum.h \
			../rtDaisySP/src/Filters/svf.h \
			../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/synthbassdrum.o ../rtDaisySP/src/Drums/synthbassdrum.cpp

synthsnaredrum.o: ../rtDaisySP/src/Drums/synthsnaredrum.cpp \
			../rtDaisySP/src/Utility/dsp.h \
			../rtDaisySP/src/Drums/synthsnaredrum.h \
			../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/synthsnaredrum.o ../rtDaisySP/src/Drums/synthsnaredrum.cpp

balance.o: 	../rtDaisySP/src/Dynamics/balance.cpp \
			../rtDaisySP/src/Dynamics/balance.h \
			../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/balance.o ../rtDaisySP/src/Dynamics/balance.cpp

compressor.o: ../rtDaisySP/src/Dynamics/compressor.cpp \
			../rtDaisySP/src/Dynamics/compressor.h \
			../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/compressor.o ../rtDaisySP/src/Dynamics/compressor.cpp

crossfade.o:	../rtDaisySP/src/Dynamics/crossfade.cpp \
				../rtDaisySP/src/Dynamics/crossfade.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/crossfade.o ../rtDaisySP/src/Dynamics/crossfade.cpp

limiter.o: 		../rtDaisySP/src/Dynamics/limiter.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Dynamics/limiter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/limiter.o ../rtDaisySP/src/Dynamics/limiter.cpp

autowah.o: 		../rtDaisySP/src/Effects/autowah.cpp \
				../rtDaisySP/src/Effects/autowah.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/autowah.o ../rtDaisySP/src/Effects/autowah.cpp

bitcrush.o: 	../rtDaisySP/src/Effects/bitcrush.cpp \
				../rtDaisySP/src/Effects/bitcrush.h \
				../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/bitcrush.o ../rtDaisySP/src/Effects/bitcrush.cpp

chorus.o: 		../rtDaisySP/src/Effects/chorus.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Effects/chorus.h \
				../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/chorus.o ../rtDaisySP/src/Effects/chorus.cpp

decimator.o: 	../rtDaisySP/src/Effects/decimator.cpp \
				../rtDaisySP/src/Effects/decimator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/decimator.o ../rtDaisySP/src/Effects/decimator.cpp

flanger.o: 		../rtDaisySP/src/Effects/flanger.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Effects/flanger.h \
				../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/flanger.o ../rtDaisySP/src/Effects/flanger.cpp

fold.o: 		../rtDaisySP/src/Effects/fold.cpp \
				../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/fold.o ../rtDaisySP/src/Effects/fold.cpp

overdrive.o: 	../rtDaisySP/src/Effects/overdrive.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Effects/overdrive.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/overdrive.o ../rtDaisySP/src/Effects/overdrive.cpp

phaser.o: 		../rtDaisySP/src/Effects/phaser.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Effects/phaser.h \
				../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/phaser.o ../rtDaisySP/src/Effects/phaser.cpp

reverbsc.o: 	../rtDaisySP/src/Effects/reverbsc.cpp \
				../rtDaisySP/src/Effects/reverbsc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/reverbsc.o ../rtDaisySP/src/Effects/reverbsc.cpp

sampleratereducer.o: ../rtDaisySP/src/Effects/sampleratereducer.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Effects/sampleratereducer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/sampleratereducer.o ../rtDaisySP/src/Effects/sampleratereducer.cpp

tremolo.o: 		../rtDaisySP/src/Effects/tremolo.cpp \
				../rtDaisySP/src/Effects/tremolo.h \
				../rtDaisySP/src/Synthesis/oscillator.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tremolo.o ../rtDaisySP/src/Effects/tremolo.cpp

allpass.o: 		../rtDaisySP/src/Filters/allpass.cpp \
				../rtDaisySP/src/Filters/allpass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/allpass.o ../rtDaisySP/src/Filters/allpass.cpp

atone.o: 		../rtDaisySP/src/Filters/atone.cpp \
				../rtDaisySP/src/Filters/atone.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/atone.o ../rtDaisySP/src/Filters/atone.cpp

biquad.o: 		../rtDaisySP/src/Filters/biquad.cpp \
				../rtDaisySP/src/Filters/biquad.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/biquad.o ../rtDaisySP/src/Filters/biquad.cpp

comb.o: 		../rtDaisySP/src/Filters/comb.cpp \
				../rtDaisySP/src/Filters/comb.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/comb.o ../rtDaisySP/src/Filters/comb.cpp

mode.o: 		../rtDaisySP/src/Filters/mode.cpp \
				../rtDaisySP/src/Filters/mode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/mode.o ../rtDaisySP/src/Filters/mode.cpp

moogladder.o: 	../rtDaisySP/src/Filters/moogladder.cpp \
				../rtDaisySP/src/Filters/moogladder.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/moogladder.o ../rtDaisySP/src/Filters/moogladder.cpp

nlfilt.o: 		../rtDaisySP/src/Filters/nlfilt.cpp \
				../rtDaisySP/src/Filters/nlfilt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/nlfilt.o ../rtDaisySP/src/Filters/nlfilt.cpp

svf.o: 			../rtDaisySP/src/Filters/svf.cpp \
				../rtDaisySP/src/Filters/svf.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/svf.o ../rtDaisySP/src/Filters/svf.cpp

tone.o: 		../rtDaisySP/src/Filters/tone.cpp \
				../rtDaisySP/src/Filters/tone.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/tone.o ../rtDaisySP/src/Filters/tone.cpp

clockednoise.o: ../rtDaisySP/src/Noise/clockednoise.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Noise/clockednoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/clockednoise.o ../rtDaisySP/src/Noise/clockednoise.cpp

grainlet.o: 	../rtDaisySP/src/Noise/grainlet.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Noise/grainlet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/grainlet.o ../rtDaisySP/src/Noise/grainlet.cpp

particle.o: 	../rtDaisySP/src/Noise/particle.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Noise/particle.h \
				../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/particle.o ../rtDaisySP/src/Noise/particle.cpp

KarplusString.o: ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/PhysicalModeling/KarplusString.h \
				../rtDaisySP/src/Dynamics/crossfade.h \
				../rtDaisySP/src/Utility/dcblock.h \
				../rtDaisySP/src/Utility/delayline.h \
				../rtDaisySP/src/Filters/svf.h \
				../rtDaisySP/src/Filters/tone.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/KarplusString.o ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp

drip.o: 		../rtDaisySP/src/PhysicalModeling/drip.cpp \
				../rtDaisySP/src/PhysicalModeling/drip.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/drip.o ../rtDaisySP/src/PhysicalModeling/drip.cpp

modalvoice.o: 	../rtDaisySP/src/PhysicalModeling/modalvoice.cpp \
				../rtDaisySP/src/PhysicalModeling/modalvoice.h \
				../rtDaisySP/src/Filters/svf.h \
				../rtDaisySP/src/PhysicalModeling/resonator.h \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Noise/dust.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/modalvoice.o ../rtDaisySP/src/PhysicalModeling/modalvoice.cpp

pluck.o: 		../rtDaisySP/src/PhysicalModeling/pluck.cpp \
				../rtDaisySP/src/PhysicalModeling/pluck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/pluck.o ../rtDaisySP/src/PhysicalModeling/pluck.cpp

resonator.o: 	../rtDaisySP/src/PhysicalModeling/resonator.cpp \
				../rtDaisySP/src/PhysicalModeling/resonator.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/resonator.o ../rtDaisySP/src/PhysicalModeling/resonator.cpp

stringvoice.o: 	../rtDaisySP/src/PhysicalModeling/stringvoice.cpp \
				../rtDaisySP/src/PhysicalModeling/stringvoice.h \
				../rtDaisySP/src/Filters/svf.h \
				../rtDaisySP/src/PhysicalModeling/KarplusString.h \
				../rtDaisySP/src/Dynamics/crossfade.h \
				../rtDaisySP/src/Utility/dcblock.h \
				../rtDaisySP/src/Utility/delayline.h \
				../rtDaisySP/src/Filters/tone.h \
				../rtDaisySP/src/Noise/dust.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/stringvoice.o ../rtDaisySP/src/PhysicalModeling/stringvoice.cpp

blosc.o: 		../rtDaisySP/src/Synthesis/blosc.cpp \
				../rtDaisySP/src/Synthesis/blosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/blosc.o ../rtDaisySP/src/Synthesis/blosc.cpp

fm2.o: 			../rtDaisySP/src/Synthesis/fm2.cpp \
				../rtDaisySP/src/Synthesis/fm2.h \
				../rtDaisySP/src/Synthesis/oscillator.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/fm2.o ../rtDaisySP/src/Synthesis/fm2.cpp

formantosc.o: 	../rtDaisySP/src/Synthesis/formantosc.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/formantosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/formantosc.o ../rtDaisySP/src/Synthesis/formantosc.cpp

oscillator.o: 	../rtDaisySP/src/Synthesis/oscillator.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/oscillator.o ../rtDaisySP/src/Synthesis/oscillator.cpp

oscillatorbank.o: ../rtDaisySP/src/Synthesis/oscillatorbank.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/oscillatorbank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/oscillatorbank.o ../rtDaisySP/src/Synthesis/oscillatorbank.cpp

variablesawosc.o: ../rtDaisySP/src/Synthesis/variablesawosc.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/variablesawosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/variablesawosc.o ../rtDaisySP/src/Synthesis/variablesawosc.cpp

variableshapeosc.o: ../rtDaisySP/src/Synthesis/variableshapeosc.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/variableshapeosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/variableshapeosc.o ../rtDaisySP/src/Synthesis/variableshapeosc.cpp

vosim.o: 		../rtDaisySP/src/Synthesis/vosim.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/vosim.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/vosim.o ../rtDaisySP/src/Synthesis/vosim.cpp

zoscillator.o: ../rtDaisySP/src/Synthesis/zoscillator.cpp \
				../rtDaisySP/src/Utility/dsp.h \
				../rtDaisySP/src/Synthesis/zoscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/zoscillator.o ../rtDaisySP/src/Synthesis/zoscillator.cpp

dcblock.o: 		../rtDaisySP/src/Utility/dcblock.cpp \
				../rtDaisySP/src/Utility/dcblock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/dcblock.o ../rtDaisySP/src/Utility/dcblock.cpp

jitter.o: 		../rtDaisySP/src/Utility/jitter.cpp \
				../rtDaisySP/src/Utility/jitter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/jitter.o ../rtDaisySP/src/Utility/jitter.cpp

metro.o: 		../rtDaisySP/src/Utility/metro.cpp \
				../rtDaisySP/src/Utility/metro.h \
				../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/metro.o ../rtDaisySP/src/Utility/metro.cpp

port.o: 		../rtDaisySP/src/Utility/port.cpp \
				../rtDaisySP/src/Utility/port.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ./bin/port.o ../rtDaisySP/src/Utility/port.cpp
