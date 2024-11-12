# setup

CXX           = g++
CXXFLAGS      = -pipe -O2 -Wall -Wextra -fPIC -D__LINUX_ALSA__
INCPATH       = -I. -I. \
				-I/usr/include/SDL2 \
				-I../rtDStudio/src \
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
LIBS          = -lpthread -lsndfile -lasound -lpthread -lgpiod -li2c -lserial -lSDL2 -lSDL2_image -lSDL2_ttf

# files

SOURCES = main.cpp \
		../rtaudio/RtAudio.cpp \
		$(wildcard ../rtDStudio/src/*.cpp) \
		$(vildcard ../rtDaisySP/src/Control/*.cpp) \
		$(vildcard ../rtDaisySP/src/Drums/*.cpp) \
		$(vildcard ../rtDaisySP/src/Dynamics/*.cpp) \
		$(vildcard ../rtDaisySP/src/Effects/*.cpp) \
		$(vildcard ../rtDaisySP/src/Filters/*.cpp) \
		$(vildcard ../rtDaisySP/src/Noise/*.cpp) \
		$(vildcard ../rtDaisySP/src/PhysicalModeling/*.cpp) \
		$(vildcard ../rtDaisySP/src/Synthesis/*.cpp) \
		$(vildcard ../rtDaisySP/src/Utility/*.cpp)
OBJECTS = bin/main.o \
		bin/RtAudio.o \
		bin/tinyxml.o \
		bin/tinyxmlerror.o \
		bin/tinyxmlparser.o \
		bin/dbass.o \
		bin/dclap.o \
		bin/dcymbal.o \
		bin/ddrum.o \
		bin/dfx.o \
		bin/dgen.o \
		bin/dhaxo.o \
		bin/dhihat.o \
		bin/dmixer.o \
		bin/dsampler.o \
		bin/dseqmidi.o \
		bin/dseqperm.o \
		bin/dsettings.o \
		bin/dsm.o \
		bin/dsnare.o \
		bin/dsound.o \
		bin/dsplit.o \
		bin/dstudio.o \
		bin/dsynthfm.o \
		bin/dsynth.o \
		bin/dsynthsub.o \
		bin/dsynthvar.o \
		bin/tclap.o \
		bin/tcymbal.o \
		bin/tdrum.o \
		bin/dwindow.o \
		bin/adenv.o \
		bin/adsr.o \
		bin/line.o \
		bin/phasor.o \
		bin/analogbassdrum.o \
		bin/analogsnaredrum.o \
		bin/hihat.o \
		bin/synthbassdrum.o \
		bin/synthsnaredrum.o \
		bin/balance.o \
		bin/compressor.o \
		bin/crossfade.o \
		bin/limiter.o \
		bin/autowah.o \
		bin/bitcrush.o \
		bin/chorus.o \
		bin/decimator.o \
		bin/flanger.o \
		bin/fold.o \
		bin/overdrive.o \
		bin/phaser.o \
		bin/reverbsc.o \
		bin/sampleratereducer.o \
		bin/tremolo.o \
		bin/allpass.o \
		bin/atone.o \
		bin/biquad.o \
		bin/comb.o \
		bin/mode.o \
		bin/moogladder.o \
		bin/nlfilt.o \
		bin/svf.o \
		bin/tone.o \
		bin/clockednoise.o \
		bin/grainlet.o \
		bin/particle.o \
		bin/KarplusString.o \
		bin/drip.o \
		bin/modalvoice.o \
		bin/pluck.o \
		bin/resonator.o \
		bin/stringvoice.o \
		bin/blosc.o \
		bin/fm2.o \
		bin/formantosc.o \
		bin/oscillator.o \
		bin/oscillatorbank.o \
		bin/variablesawosc.o \
		bin/variableshapeosc.o \
		bin/vosim.o \
		bin/zoscillator.o \
		bin/dcblock.o \
		bin/jitter.o \
		bin/metro.o \
		bin/port.o
TARGET = dstudio

# link

dstudio:  $(OBJECTS)  
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# compile

bin/main.o: main.cpp \
		main.h \
		../rtaudio/RtAudio.h \
		../rtDaisySP/src/daisysp.h \
		$(wildcard ../rtDaisySP/src/Control/*.h) \
		$(wildcard ../rtDaisySP/src/Drums/*.h) \
		$(wildcard ../rtDaisySP/src/Synthesis/*.h) \
		$(wildcard ../rtDaisySP/src/Utility/*.h) \
		$(wildcard ../rtDaisySP/src/Filters/*.h) \
		$(wildcard ../rtDaisySP/src/Dynamics/*.h) \
		$(wildcard ../rtDaisySP/src/Effects/*.h) \
		$(wildcard ../rtDaisySP/src/Noise/*.h) \
		$(wildcard ../rtDaisySP/src/PhysicalModeling/*.h) \
		$(wildcard ../rtDStudio/src/*.h)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/main.o main.cpp

bin/dwindow.o: ../rtDStudio/src/dwindow.cpp \
			../rtDStudio/src/dwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dwindow.o ../rtDStudio/src/dwindow.cpp

bin/RtAudio.o: ../rtaudio/RtAudio.cpp ../rtaudio/RtAudio.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/RtAudio.o ../rtaudio/RtAudio.cpp

bin/tinyxml.o: ../rtDStudio/src/libs/tinyxml.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tinyxml.o ../rtDStudio/src/libs/tinyxml.cpp

bin/tinyxmlerror.o: ../rtDStudio/src/libs/tinyxmlerror.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tinyxmlerror.o ../rtDStudio/src/libs/tinyxmlerror.cpp

bin/tinyxmlparser.o: ../rtDStudio/src/libs/tinyxmlparser.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tinyxmlparser.o ../rtDStudio/src/libs/tinyxmlparser.cpp

bin/dbass.o: ../rtDStudio/src/dbass.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dbass.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dbass.o ../rtDStudio/src/dbass.cpp

bin/dclap.o: ../rtDStudio/src/dclap.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dclap.h \
		../rtDStudio/src/tclap.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dclap.o ../rtDStudio/src/dclap.cpp

bin/dcymbal.o: ../rtDStudio/src/dcymbal.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/tcymbal.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDStudio/src/dcymbal.h \
		../rtDStudio/src/dsound.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dcymbal.o ../rtDStudio/src/dcymbal.cpp

bin/ddrum.o: ../rtDStudio/src/ddrum.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/ddrum.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/ddrum.o ../rtDStudio/src/ddrum.cpp

bin/dfx.o: ../rtDStudio/src/dfx.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dfx.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Effects/tremolo.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/flanger.h \
		../rtDaisySP/src/Effects/decimator.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dfx.o ../rtDStudio/src/dfx.cpp

bin/dgen.o: ../rtDStudio/src/dgen.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dgen.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Effects/reverbsc.h \
		../rtDStudio/src/dseq.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dgen.o ../rtDStudio/src/dgen.cpp

bin/dhaxo.o: ../rtDStudio/src/dgen.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dhaxo.h \
		../rtDStudio/src/dhaxo.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dhaxo.o ../rtDStudio/src/dhaxo.cpp

bin/dhihat.o: ../rtDStudio/src/dhihat.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsnare.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDStudio/src/dhihat.h \
		../rtDaisySP/src/Drums/hihat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dhihat.o ../rtDStudio/src/dhihat.cpp

bin/dmixer.o: ../rtDStudio/src/dmixer.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Effects/reverbsc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dmixer.o ../rtDStudio/src/dmixer.cpp

bin/dsampler.o: ../rtDStudio/src/dsampler.cpp \
		../rtDStudio/src/dsampler.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsampler.o ../rtDStudio/src/dsampler.cpp

bin/dseqmidi.o: ../rtDStudio/src/dseqmidi.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dseqmidi.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Effects/reverbsc.h \
		../rtDStudio/src/dseq.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dseqmidi.o ../rtDStudio/src/dseqmidi.cpp

bin/dseqperm.o: ../rtDStudio/src/dseqperm.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dseqperm.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Effects/reverbsc.h \
		../rtDStudio/src/dseq.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dseqperm.o ../rtDStudio/src/dseqperm.cpp

bin/dsettings.o: ../rtDStudio/src/dsettings.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsettings.h \
		../rtDStudio/src/dsynthvar.h \
		../rtDStudio/src/dsynthfm.h \
		../rtDStudio/src/dsampler.h \
		../rtDStudio/src/dbass.h \
		../rtDStudio/src/dhihat.h \
		../rtDStudio/src/dsnare.h \
		../rtDStudio/src/dclap.h \
		../rtDStudio/src/dcymbal.h \
		../rtDStudio/src/ddrum.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dmixer.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Effects/reverbsc.h \
		../rtDStudio/src/dseq.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsettings.o ../rtDStudio/src/dsettings.cpp

bin/dsm.o: ../rtDStudio/src/dsm.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsm.o ../rtDStudio/src/dsm.cpp

bin/dsnare.o: ../rtDStudio/src/dsnare.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsnare.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsnare.o ../rtDStudio/src/dsnare.cpp

bin/dsound.o: ../rtDStudio/src/dsound.cpp \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsound.o ../rtDStudio/src/dsound.cpp

bin/dsplit.o: ../rtDStudio/src/dsplit.cpp \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsplit.h \
		../rtDStudio/src/dsound.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsplit.o ../rtDStudio/src/dsplit.cpp

bin/dstudio.o: ../rtDStudio/src/dstudio.cpp \
		../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dstudio.o ../rtDStudio/src/dstudio.cpp

bin/dsynth.o: ../rtDStudio/src/dsynth.cpp \
		../rtDStudio/src/dsynth.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsynth.o ../rtDStudio/src/dsynth.cpp

bin/dsynthfm.o: ../rtDStudio/src/dsynthfm.cpp \
		../rtDStudio/src/dsynthfm.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Synthesis/fm2.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsynthfm.o ../rtDStudio/src/dsynthfm.cpp

bin/dsynthsub.o: ../rtDStudio/src/dsynthsub.cpp \
		../rtDStudio/src/dsynthsub.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsynthsub.o ../rtDStudio/src/dsynthsub.cpp

bin/dsynthvar.o: ../rtDStudio/src/dsynthvar.cpp \
		../rtDStudio/src/dsynthvar.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dsm.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/variableshapeosc.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dsynthvar.o ../rtDStudio/src/dsynthvar.cpp

bin/tclap.o: ../rtDStudio/src/tclap.cpp \
		../rtDStudio/src/tclap.h \
		../rtDStudio/src/dstudio.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tclap.o ../rtDStudio/src/tclap.cpp

bin/tcymbal.o: ../rtDStudio/src/tcymbal.cpp \
		../rtDStudio/src/tcymbal.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tcymbal.o ../rtDStudio/src/tcymbal.cpp

bin/tdrum.o: ../rtDStudio/src/tdrum.cpp \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tdrum.o ../rtDStudio/src/tdrum.cpp

bin/adenv.o: ../rtDaisySP/src/Control/adenv.cpp \
		../rtDaisySP/src/Control/adenv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/adenv.o ../rtDaisySP/src/Control/adenv.cpp

bin/adsr.o: ../rtDaisySP/src/Control/adsr.cpp \
		../rtDaisySP/src/Control/adsr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/adsr.o ../rtDaisySP/src/Control/adsr.cpp

bin/line.o: ../rtDaisySP/src/Control/line.cpp \
		../rtDaisySP/src/Control/line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/line.o ../rtDaisySP/src/Control/line.cpp

bin/phasor.o: ../rtDaisySP/src/Control/phasor.cpp \
		../rtDaisySP/src/Control/phasor.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/phasor.o ../rtDaisySP/src/Control/phasor.cpp

bin/analogbassdrum.o: ../rtDaisySP/src/Drums/analogbassdrum.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/analogbassdrum.o ../rtDaisySP/src/Drums/analogbassdrum.cpp

bin/analogsnaredrum.o: ../rtDaisySP/src/Drums/analogsnaredrum.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/analogsnaredrum.o ../rtDaisySP/src/Drums/analogsnaredrum.cpp

bin/hihat.o: ../rtDaisySP/src/Drums/hihat.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/hihat.o ../rtDaisySP/src/Drums/hihat.cpp

bin/synthbassdrum.o: ../rtDaisySP/src/Drums/synthbassdrum.cpp \
		../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/synthbassdrum.o ../rtDaisySP/src/Drums/synthbassdrum.cpp

bin/synthsnaredrum.o: ../rtDaisySP/src/Drums/synthsnaredrum.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/synthsnaredrum.o ../rtDaisySP/src/Drums/synthsnaredrum.cpp

bin/balance.o: ../rtDaisySP/src/Dynamics/balance.cpp \
		../rtDaisySP/src/Dynamics/balance.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/balance.o ../rtDaisySP/src/Dynamics/balance.cpp

bin/compressor.o: ../rtDaisySP/src/Dynamics/compressor.cpp \
		../rtDaisySP/src/Dynamics/compressor.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/compressor.o ../rtDaisySP/src/Dynamics/compressor.cpp

bin/crossfade.o: ../rtDaisySP/src/Dynamics/crossfade.cpp \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/crossfade.o ../rtDaisySP/src/Dynamics/crossfade.cpp

bin/limiter.o: ../rtDaisySP/src/Dynamics/limiter.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Dynamics/limiter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/limiter.o ../rtDaisySP/src/Dynamics/limiter.cpp

bin/autowah.o: ../rtDaisySP/src/Effects/autowah.cpp \
		../rtDaisySP/src/Effects/autowah.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/autowah.o ../rtDaisySP/src/Effects/autowah.cpp

bin/bitcrush.o: ../rtDaisySP/src/Effects/bitcrush.cpp \
		../rtDaisySP/src/Effects/bitcrush.h \
		../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/bitcrush.o ../rtDaisySP/src/Effects/bitcrush.cpp

bin/chorus.o: ../rtDaisySP/src/Effects/chorus.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/chorus.o ../rtDaisySP/src/Effects/chorus.cpp

bin/decimator.o: ../rtDaisySP/src/Effects/decimator.cpp \
		../rtDaisySP/src/Effects/decimator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/decimator.o ../rtDaisySP/src/Effects/decimator.cpp

bin/flanger.o: ../rtDaisySP/src/Effects/flanger.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/flanger.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/flanger.o ../rtDaisySP/src/Effects/flanger.cpp

bin/fold.o: ../rtDaisySP/src/Effects/fold.cpp \
		../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/fold.o ../rtDaisySP/src/Effects/fold.cpp

bin/overdrive.o: ../rtDaisySP/src/Effects/overdrive.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/overdrive.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/overdrive.o ../rtDaisySP/src/Effects/overdrive.cpp

bin/phaser.o: ../rtDaisySP/src/Effects/phaser.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/phaser.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/phaser.o ../rtDaisySP/src/Effects/phaser.cpp

bin/reverbsc.o: ../rtDaisySP/src/Effects/reverbsc.cpp \
		../rtDaisySP/src/Effects/reverbsc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/reverbsc.o ../rtDaisySP/src/Effects/reverbsc.cpp

bin/sampleratereducer.o: ../rtDaisySP/src/Effects/sampleratereducer.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/sampleratereducer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/sampleratereducer.o ../rtDaisySP/src/Effects/sampleratereducer.cpp

bin/tremolo.o: ../rtDaisySP/src/Effects/tremolo.cpp \
		../rtDaisySP/src/Effects/tremolo.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tremolo.o ../rtDaisySP/src/Effects/tremolo.cpp

bin/allpass.o: ../rtDaisySP/src/Filters/allpass.cpp \
		../rtDaisySP/src/Filters/allpass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/allpass.o ../rtDaisySP/src/Filters/allpass.cpp

bin/atone.o: ../rtDaisySP/src/Filters/atone.cpp \
		../rtDaisySP/src/Filters/atone.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/atone.o ../rtDaisySP/src/Filters/atone.cpp

bin/biquad.o: ../rtDaisySP/src/Filters/biquad.cpp \
		../rtDaisySP/src/Filters/biquad.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/biquad.o ../rtDaisySP/src/Filters/biquad.cpp

bin/comb.o: ../rtDaisySP/src/Filters/comb.cpp \
		../rtDaisySP/src/Filters/comb.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/comb.o ../rtDaisySP/src/Filters/comb.cpp

bin/mode.o: ../rtDaisySP/src/Filters/mode.cpp \
		../rtDaisySP/src/Filters/mode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/mode.o ../rtDaisySP/src/Filters/mode.cpp

bin/moogladder.o: ../rtDaisySP/src/Filters/moogladder.cpp \
		../rtDaisySP/src/Filters/moogladder.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/moogladder.o ../rtDaisySP/src/Filters/moogladder.cpp

bin/nlfilt.o: ../rtDaisySP/src/Filters/nlfilt.cpp \
		../rtDaisySP/src/Filters/nlfilt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/nlfilt.o ../rtDaisySP/src/Filters/nlfilt.cpp

bin/svf.o: ../rtDaisySP/src/Filters/svf.cpp \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/svf.o ../rtDaisySP/src/Filters/svf.cpp

bin/tone.o: ../rtDaisySP/src/Filters/tone.cpp \
		../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/tone.o ../rtDaisySP/src/Filters/tone.cpp

bin/clockednoise.o: ../rtDaisySP/src/Noise/clockednoise.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/clockednoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/clockednoise.o ../rtDaisySP/src/Noise/clockednoise.cpp

bin/grainlet.o: ../rtDaisySP/src/Noise/grainlet.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/grainlet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/grainlet.o ../rtDaisySP/src/Noise/grainlet.cpp

bin/particle.o: ../rtDaisySP/src/Noise/particle.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/particle.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/particle.o ../rtDaisySP/src/Noise/particle.cpp

bin/KarplusString.o: ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Filters/tone.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/KarplusString.o ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp

bin/drip.o: ../rtDaisySP/src/PhysicalModeling/drip.cpp \
		../rtDaisySP/src/PhysicalModeling/drip.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/drip.o ../rtDaisySP/src/PhysicalModeling/drip.cpp

bin/modalvoice.o: ../rtDaisySP/src/PhysicalModeling/modalvoice.cpp \
		../rtDaisySP/src/PhysicalModeling/modalvoice.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/dust.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/modalvoice.o ../rtDaisySP/src/PhysicalModeling/modalvoice.cpp

bin/pluck.o: ../rtDaisySP/src/PhysicalModeling/pluck.cpp \
		../rtDaisySP/src/PhysicalModeling/pluck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/pluck.o ../rtDaisySP/src/PhysicalModeling/pluck.cpp

bin/resonator.o: ../rtDaisySP/src/PhysicalModeling/resonator.cpp \
		../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/resonator.o ../rtDaisySP/src/PhysicalModeling/resonator.cpp

bin/stringvoice.o: ../rtDaisySP/src/PhysicalModeling/stringvoice.cpp \
		../rtDaisySP/src/PhysicalModeling/stringvoice.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Noise/dust.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/stringvoice.o ../rtDaisySP/src/PhysicalModeling/stringvoice.cpp

bin/blosc.o: ../rtDaisySP/src/Synthesis/blosc.cpp \
		../rtDaisySP/src/Synthesis/blosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/blosc.o ../rtDaisySP/src/Synthesis/blosc.cpp

bin/fm2.o: ../rtDaisySP/src/Synthesis/fm2.cpp \
		../rtDaisySP/src/Synthesis/fm2.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/fm2.o ../rtDaisySP/src/Synthesis/fm2.cpp

bin/formantosc.o: ../rtDaisySP/src/Synthesis/formantosc.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/formantosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/formantosc.o ../rtDaisySP/src/Synthesis/formantosc.cpp

bin/oscillator.o: ../rtDaisySP/src/Synthesis/oscillator.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/oscillator.o ../rtDaisySP/src/Synthesis/oscillator.cpp

bin/oscillatorbank.o: ../rtDaisySP/src/Synthesis/oscillatorbank.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/oscillatorbank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/oscillatorbank.o ../rtDaisySP/src/Synthesis/oscillatorbank.cpp

bin/variablesawosc.o: ../rtDaisySP/src/Synthesis/variablesawosc.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/variablesawosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/variablesawosc.o ../rtDaisySP/src/Synthesis/variablesawosc.cpp

bin/variableshapeosc.o: ../rtDaisySP/src/Synthesis/variableshapeosc.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/variableshapeosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/variableshapeosc.o ../rtDaisySP/src/Synthesis/variableshapeosc.cpp

bin/vosim.o: ../rtDaisySP/src/Synthesis/vosim.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/vosim.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/vosim.o ../rtDaisySP/src/Synthesis/vosim.cpp

bin/zoscillator.o: ../rtDaisySP/src/Synthesis/zoscillator.cpp \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/zoscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/zoscillator.o ../rtDaisySP/src/Synthesis/zoscillator.cpp

bin/dcblock.o: ../rtDaisySP/src/Utility/dcblock.cpp \
		../rtDaisySP/src/Utility/dcblock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/dcblock.o ../rtDaisySP/src/Utility/dcblock.cpp

bin/jitter.o: ../rtDaisySP/src/Utility/jitter.cpp \
		../rtDaisySP/src/Utility/jitter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/jitter.o ../rtDaisySP/src/Utility/jitter.cpp

bin/metro.o: ../rtDaisySP/src/Utility/metro.cpp \
		../rtDaisySP/src/Utility/metro.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/metro.o ../rtDaisySP/src/Utility/metro.cpp

bin/port.o: ../rtDaisySP/src/Utility/port.cpp \
		../rtDaisySP/src/Utility/port.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/port.o ../rtDaisySP/src/Utility/port.cpp
