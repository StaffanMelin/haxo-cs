MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -D__LINUX_ALSA__
CFLAGS        = -pipe -O2 -Wall -Wextra -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -Wextra -fPIC $(DEFINES)
INCPATH       = -I. -I. -I../rtDStudio/src -I../rtDaisySP/src/Control -I../rtDaisySP/src/Drums -I../rtDaisySP/src/Dynamics -I../rtDaisySP/src/Effects -I../rtDaisySP/src/Filters -I../rtDaisySP/src/Noise -I../rtDaisySP/src/PhysicalModeling -I../rtDaisySP/src/Synthesis -I../rtDaisySP/src/Utility
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lpthread -lsndfile -lasound -lpthread -lgpiod -li2c

####### Files

SOURCES       = main.cpp \
		rtApp.cpp \
		../rtaudio/RtAudio.cpp \
		../rtDStudio/src/dbass.cpp \
		../rtDStudio/src/dclap.cpp \
		../rtDStudio/src/dcymbal.cpp \
		../rtDStudio/src/ddrum.cpp \
		../rtDStudio/src/dfx.cpp \
		../rtDStudio/src/dgen.cpp \
		../rtDStudio/src/dhaxo.cpp \
		../rtDStudio/src/dhihat.cpp \
		../rtDStudio/src/dmixer.cpp \
		../rtDStudio/src/dsampler.cpp \
		../rtDStudio/src/dseqmidi.cpp \
		../rtDStudio/src/dseqperm.cpp \
		../rtDStudio/src/dsettings.cpp \
		../rtDStudio/src/dsm.cpp \
		../rtDStudio/src/dsnare.cpp \
		../rtDStudio/src/dsound.cpp \
		../rtDStudio/src/dsplit.cpp \
		../rtDStudio/src/dstudio.cpp \
		../rtDStudio/src/dsynthfm.cpp \
		../rtDStudio/src/dsynthsub.cpp \
		../rtDStudio/src/dsynthvar.cpp \
		../rtDStudio/src/tclap.cpp \
		../rtDStudio/src/tcymbal.cpp \
		../rtDStudio/src/tdrum.cpp \
		../rtDaisySP/src/Control/adenv.cpp \
		../rtDaisySP/src/Control/adsr.cpp \
		../rtDaisySP/src/Control/line.cpp \
		../rtDaisySP/src/Control/phasor.cpp \
		../rtDaisySP/src/Drums/analogbassdrum.cpp \
		../rtDaisySP/src/Drums/analogsnaredrum.cpp \
		../rtDaisySP/src/Drums/hihat.cpp \
		../rtDaisySP/src/Drums/synthbassdrum.cpp \
		../rtDaisySP/src/Drums/synthsnaredrum.cpp \
		../rtDaisySP/src/Dynamics/balance.cpp \
		../rtDaisySP/src/Dynamics/compressor.cpp \
		../rtDaisySP/src/Dynamics/crossfade.cpp \
		../rtDaisySP/src/Dynamics/limiter.cpp \
		../rtDaisySP/src/Effects/autowah.cpp \
		../rtDaisySP/src/Effects/bitcrush.cpp \
		../rtDaisySP/src/Effects/chorus.cpp \
		../rtDaisySP/src/Effects/decimator.cpp \
		../rtDaisySP/src/Effects/flanger.cpp \
		../rtDaisySP/src/Effects/fold.cpp \
		../rtDaisySP/src/Effects/overdrive.cpp \
		../rtDaisySP/src/Effects/phaser.cpp \
		../rtDaisySP/src/Effects/reverbsc.cpp \
		../rtDaisySP/src/Effects/sampleratereducer.cpp \
		../rtDaisySP/src/Effects/tremolo.cpp \
		../rtDaisySP/src/Filters/allpass.cpp \
		../rtDaisySP/src/Filters/atone.cpp \
		../rtDaisySP/src/Filters/biquad.cpp \
		../rtDaisySP/src/Filters/comb.cpp \
		../rtDaisySP/src/Filters/mode.cpp \
		../rtDaisySP/src/Filters/moogladder.cpp \
		../rtDaisySP/src/Filters/nlfilt.cpp \
		../rtDaisySP/src/Filters/svf.cpp \
		../rtDaisySP/src/Filters/tone.cpp \
		../rtDaisySP/src/Noise/clockednoise.cpp \
		../rtDaisySP/src/Noise/grainlet.cpp \
		../rtDaisySP/src/Noise/particle.cpp \
		../rtDaisySP/src/PhysicalModeling/KarplusString.cpp \
		../rtDaisySP/src/PhysicalModeling/drip.cpp \
		../rtDaisySP/src/PhysicalModeling/modalvoice.cpp \
		../rtDaisySP/src/PhysicalModeling/pluck.cpp \
		../rtDaisySP/src/PhysicalModeling/resonator.cpp \
		../rtDaisySP/src/PhysicalModeling/stringvoice.cpp \
		../rtDaisySP/src/Synthesis/blosc.cpp \
		../rtDaisySP/src/Synthesis/fm2.cpp \
		../rtDaisySP/src/Synthesis/formantosc.cpp \
		../rtDaisySP/src/Synthesis/oscillator.cpp \
		../rtDaisySP/src/Synthesis/oscillatorbank.cpp \
		../rtDaisySP/src/Synthesis/variablesawosc.cpp \
		../rtDaisySP/src/Synthesis/variableshapeosc.cpp \
		../rtDaisySP/src/Synthesis/vosim.cpp \
		../rtDaisySP/src/Synthesis/zoscillator.cpp \
		../rtDaisySP/src/Utility/dcblock.cpp \
		../rtDaisySP/src/Utility/jitter.cpp \
		../rtDaisySP/src/Utility/metro.cpp \
		../rtDaisySP/src/Utility/port.cpp 
OBJECTS       = main.o \
		rtApp.o \
		RtAudio.o \
		tinyxml.o \
		tinyxmlerror.o \
		tinyxmlparser.o \
		dbass.o \
		dclap.o \
		dcymbal.o \
		ddrum.o \
		dfx.o \
		dgen.o \
		dhaxo.o \
		dhihat.o \
		dmixer.o \
		dsampler.o \
		dseqmidi.o \
		dseqperm.o \
		dsettings.o \
		dsm.o \
		dsnare.o \
		dsound.o \
		dsplit.o \
		dstudio.o \
		dsynthfm.o \
		dsynthsub.o \
		dsynthvar.o \
		tclap.o \
		tcymbal.o \
		tdrum.o \
		adenv.o \
		adsr.o \
		line.o \
		phasor.o \
		analogbassdrum.o \
		analogsnaredrum.o \
		hihat.o \
		synthbassdrum.o \
		synthsnaredrum.o \
		balance.o \
		compressor.o \
		crossfade.o \
		limiter.o \
		autowah.o \
		bitcrush.o \
		chorus.o \
		decimator.o \
		flanger.o \
		fold.o \
		overdrive.o \
		phaser.o \
		reverbsc.o \
		sampleratereducer.o \
		tremolo.o \
		allpass.o \
		atone.o \
		biquad.o \
		comb.o \
		mode.o \
		moogladder.o \
		nlfilt.o \
		svf.o \
		tone.o \
		clockednoise.o \
		grainlet.o \
		particle.o \
		KarplusString.o \
		drip.o \
		modalvoice.o \
		pluck.o \
		resonator.o \
		stringvoice.o \
		blosc.o \
		fm2.o \
		formantosc.o \
		oscillator.o \
		oscillatorbank.o \
		variablesawosc.o \
		variableshapeosc.o \
		vosim.o \
		zoscillator.o \
		dcblock.o \
		jitter.o \
		metro.o \
		port.o
TARGET        = rtDStudioExample


#first: all
####### Build rules

rtDStudioDemo:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

all: Makefile rtDStudioExample

####### Compile

main.o: main.cpp ../rtaudio/RtAudio.h \
		../rtDaisySP/src/daisysp.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Control/line.h \
		../rtDaisySP/src/Control/phasor.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/Dynamics/balance.h \
		../rtDaisySP/src/Dynamics/compressor.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Dynamics/limiter.h \
		../rtDaisySP/src/Effects/autowah.h \
		../rtDaisySP/src/Effects/bitcrush.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/decimator.h \
		../rtDaisySP/src/Effects/flanger.h \
		../rtDaisySP/src/Effects/fold.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Effects/reverbsc.h \
		../rtDaisySP/src/Effects/phaser.h \
		../rtDaisySP/src/Effects/pitchshifter.h \
		../rtDaisySP/src/Effects/sampleratereducer.h \
		../rtDaisySP/src/Effects/tremolo.h \
		../rtDaisySP/src/Filters/allpass.h \
		../rtDaisySP/src/Filters/atone.h \
		../rtDaisySP/src/Filters/biquad.h \
		../rtDaisySP/src/Filters/comb.h \
		../rtDaisySP/src/Filters/mode.h \
		../rtDaisySP/src/Filters/moogladder.h \
		../rtDaisySP/src/Filters/nlfilt.h \
		../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Filters/fir.h \
		../rtDaisySP/src/Noise/clockednoise.h \
		../rtDaisySP/src/Noise/dust.h \
		../rtDaisySP/src/Noise/fractal_noise.h \
		../rtDaisySP/src/Noise/grainlet.h \
		../rtDaisySP/src/Noise/particle.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDaisySP/src/PhysicalModeling/drip.h \
		../rtDaisySP/src/PhysicalModeling/modalvoice.h \
		../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/PhysicalModeling/pluck.h \
		../rtDaisySP/src/PhysicalModeling/PolyPluck.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/PhysicalModeling/stringvoice.h \
		../rtDaisySP/src/Synthesis/blosc.h \
		../rtDaisySP/src/Synthesis/fm2.h \
		../rtDaisySP/src/Synthesis/formantosc.h \
		../rtDaisySP/src/Synthesis/harmonic_osc.h \
		../rtDaisySP/src/Synthesis/oscillatorbank.h \
		../rtDaisySP/src/Synthesis/variablesawosc.h \
		../rtDaisySP/src/Synthesis/variableshapeosc.h \
		../rtDaisySP/src/Synthesis/vosim.h \
		../rtDaisySP/src/Synthesis/zoscillator.h \
		../rtDaisySP/src/Utility/jitter.h \
		../rtDaisySP/src/Utility/looper.h \
		../rtDaisySP/src/Utility/maytrig.h \
		../rtDaisySP/src/Utility/metro.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Utility/samplehold.h \
		../rtDaisySP/src/Utility/smooth_random.h \
		main.h \
		rtApp.h \
		../rtDStudio/src/dbass.h \
		../rtDStudio/src/dclap.h \
		../rtDStudio/src/dcymbal.h \
		../rtDStudio/src/ddrum.h \
		../rtDStudio/src/dfx.h \
		../rtDStudio/src/dgen.h \
		../rtDStudio/src/dhaxo.h \
		../rtDStudio/src/dhihat.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsampler.h \
		../rtDStudio/src/dseq.h \
		../rtDStudio/src/dseqmidi.h \
		../rtDStudio/src/dseqperm.h \
		../rtDStudio/src/dsettings.h \
		../rtDStudio/src/dsm.h \
		../rtDStudio/src/dsnare.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dsplit.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsynthfm.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDStudio/src/dsynthvar.h \
		../rtDStudio/src/tclap.h \
		../rtDStudio/src/tcymbal.h \
		../rtDStudio/src/tdrum.h

	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

rtApp.o: rtApp.cpp rtApp.h \
		../rtDStudio/src/dbass.h \
		../rtDStudio/src/dclap.h \
		../rtDStudio/src/dcymbal.h \
		../rtDStudio/src/ddrum.h \
		../rtDStudio/src/dfx.h \
		../rtDStudio/src/dgen.h \
		../rtDStudio/src/dhaxo.h \
		../rtDStudio/src/dhihat.h \
		../rtDStudio/src/dmixer.h \
		../rtDStudio/src/dsampler.h \
		../rtDStudio/src/dseq.h \
		../rtDStudio/src/dseqmidi.h \
		../rtDStudio/src/dseqperm.h \
		../rtDStudio/src/dsettings.h \
		../rtDStudio/src/dsm.h \
		../rtDStudio/src/dsnare.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dsplit.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsynthfm.h \
		../rtDStudio/src/dsynthsub.h \
		../rtDStudio/src/dsynthvar.h \
		../rtDStudio/src/tclap.h \
		../rtDStudio/src/tcymbal.h \
		../rtDStudio/src/tdrum.h \
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
		../rtDaisySP/src/Synthesis/fm2.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/daisysp.h \
		../rtDaisySP/src/Control/line.h \
		../rtDaisySP/src/Control/phasor.h \
		../rtDaisySP/src/Dynamics/balance.h \
		../rtDaisySP/src/Dynamics/compressor.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Dynamics/limiter.h \
		../rtDaisySP/src/Effects/autowah.h \
		../rtDaisySP/src/Effects/bitcrush.h \
		../rtDaisySP/src/Effects/decimator.h \
		../rtDaisySP/src/Effects/flanger.h \
		../rtDaisySP/src/Effects/fold.h \
		../rtDaisySP/src/Effects/phaser.h \
		../rtDaisySP/src/Effects/pitchshifter.h \
		../rtDaisySP/src/Effects/sampleratereducer.h \
		../rtDaisySP/src/Effects/tremolo.h \
		../rtDaisySP/src/Filters/allpass.h \
		../rtDaisySP/src/Filters/atone.h \
		../rtDaisySP/src/Filters/biquad.h \
		../rtDaisySP/src/Filters/comb.h \
		../rtDaisySP/src/Filters/mode.h \
		../rtDaisySP/src/Filters/moogladder.h \
		../rtDaisySP/src/Filters/nlfilt.h \
		../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Filters/fir.h \
		../rtDaisySP/src/Noise/clockednoise.h \
		../rtDaisySP/src/Noise/dust.h \
		../rtDaisySP/src/Noise/fractal_noise.h \
		../rtDaisySP/src/Noise/grainlet.h \
		../rtDaisySP/src/Noise/particle.h \
		../rtDaisySP/src/PhysicalModeling/drip.h \
		../rtDaisySP/src/PhysicalModeling/modalvoice.h \
		../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/PhysicalModeling/pluck.h \
		../rtDaisySP/src/PhysicalModeling/PolyPluck.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/PhysicalModeling/stringvoice.h \
		../rtDaisySP/src/Synthesis/blosc.h \
		../rtDaisySP/src/Synthesis/formantosc.h \
		../rtDaisySP/src/Synthesis/harmonic_osc.h \
		../rtDaisySP/src/Synthesis/oscillatorbank.h \
		../rtDaisySP/src/Synthesis/variablesawosc.h \
		../rtDaisySP/src/Synthesis/variableshapeosc.h \
		../rtDaisySP/src/Synthesis/vosim.h \
		../rtDaisySP/src/Synthesis/zoscillator.h \
		../rtDaisySP/src/Utility/jitter.h \
		../rtDaisySP/src/Utility/looper.h \
		../rtDaisySP/src/Utility/maytrig.h \
		../rtDaisySP/src/Utility/metro.h \
		../rtDaisySP/src/Utility/samplehold.h \
		../rtDaisySP/src/Utility/smooth_random.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rtApp.o rtApp.cpp

RtAudio.o: ../rtaudio/RtAudio.cpp ../rtaudio/RtAudio.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RtAudio.o ../rtaudio/RtAudio.cpp

tinyxml.o: ../rtDStudio/src/libs/tinyxml.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxml.o ../rtDStudio/src/libs/tinyxml.cpp

tinyxmlerror.o: ../rtDStudio/src/libs/tinyxmlerror.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxmlerror.o ../rtDStudio/src/libs/tinyxmlerror.cpp

tinyxmlparser.o: ../rtDStudio/src/libs/tinyxmlparser.cpp ../rtDStudio/src/libs/tinyxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxmlparser.o ../rtDStudio/src/libs/tinyxmlparser.cpp

dbass.o: ../rtDStudio/src/dbass.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dbass.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dbass.o ../rtDStudio/src/dbass.cpp

dclap.o: ../rtDStudio/src/dclap.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/dclap.h \
		../rtDStudio/src/tclap.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dclap.o ../rtDStudio/src/dclap.cpp

dcymbal.o: ../rtDStudio/src/dcymbal.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/tcymbal.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/whitenoise.h \
		../rtDStudio/src/dcymbal.h \
		../rtDStudio/src/dsound.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dcymbal.o ../rtDStudio/src/dcymbal.cpp

ddrum.o: ../rtDStudio/src/ddrum.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/ddrum.h \
		../rtDStudio/src/dsound.h \
		../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ddrum.o ../rtDStudio/src/ddrum.cpp

dfx.o: ../rtDStudio/src/dfx.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dfx.o ../rtDStudio/src/dfx.cpp

dgen.o: ../rtDStudio/src/dgen.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dgen.o ../rtDStudio/src/dgen.cpp

dhaxo.o: ../rtDStudio/src/dgen.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dhaxo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dhaxo.o ../rtDStudio/src/dhaxo.cpp

dhihat.o: ../rtDStudio/src/dhihat.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dhihat.o ../rtDStudio/src/dhihat.cpp

dmixer.o: ../rtDStudio/src/dmixer.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dmixer.o ../rtDStudio/src/dmixer.cpp

dsampler.o: ../rtDStudio/src/dsampler.cpp ../rtDStudio/src/dsampler.h \
		../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsound.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Control/adsr.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Effects/overdrive.h \
		../rtDaisySP/src/Utility/port.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsampler.o ../rtDStudio/src/dsampler.cpp

dseqmidi.o: ../rtDStudio/src/dseqmidi.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dseqmidi.o ../rtDStudio/src/dseqmidi.cpp

dseqperm.o: ../rtDStudio/src/dseqperm.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dseqperm.o ../rtDStudio/src/dseqperm.cpp

dsettings.o: ../rtDStudio/src/dsettings.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsettings.o ../rtDStudio/src/dsettings.cpp

dsm.o: ../rtDStudio/src/dsm.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsm.o ../rtDStudio/src/dsm.cpp

dsnare.o: ../rtDStudio/src/dsnare.cpp ../rtDStudio/src/dstudio.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsnare.o ../rtDStudio/src/dsnare.cpp

dsound.o: ../rtDStudio/src/dsound.cpp ../rtDStudio/src/dsound.h \
		../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsound.o ../rtDStudio/src/dsound.cpp

dsplit.o: ../rtDStudio/src/dsplit.cpp ../rtDStudio/src/dstudio.h \
		../rtDStudio/src/dsplit.h \
		../rtDStudio/src/dsound.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsplit.o ../rtDStudio/src/dsplit.cpp

dstudio.o: ../rtDStudio/src/dstudio.cpp ../rtDStudio/src/dstudio.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dstudio.o ../rtDStudio/src/dstudio.cpp

dsynthfm.o: ../rtDStudio/src/dsynthfm.cpp ../rtDStudio/src/dsynthfm.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsynthfm.o ../rtDStudio/src/dsynthfm.cpp

dsynthsub.o: ../rtDStudio/src/dsynthsub.cpp ../rtDStudio/src/dsynthsub.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsynthsub.o ../rtDStudio/src/dsynthsub.cpp

dsynthvar.o: ../rtDStudio/src/dsynthvar.cpp ../rtDStudio/src/dsynthvar.h \
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
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dsynthvar.o ../rtDStudio/src/dsynthvar.cpp

tclap.o: ../rtDStudio/src/tclap.cpp ../rtDStudio/src/tclap.h \
		../rtDStudio/src/dstudio.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tclap.o ../rtDStudio/src/tclap.cpp

tcymbal.o: ../rtDStudio/src/tcymbal.cpp ../rtDStudio/src/tcymbal.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/whitenoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tcymbal.o ../rtDStudio/src/tcymbal.cpp

tdrum.o: ../rtDStudio/src/tdrum.cpp ../rtDStudio/src/tdrum.h \
		../rtDaisySP/src/Control/adenv.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tdrum.o ../rtDStudio/src/tdrum.cpp

adenv.o: ../rtDaisySP/src/Control/adenv.cpp ../rtDaisySP/src/Control/adenv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o adenv.o ../rtDaisySP/src/Control/adenv.cpp

adsr.o: ../rtDaisySP/src/Control/adsr.cpp ../rtDaisySP/src/Control/adsr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o adsr.o ../rtDaisySP/src/Control/adsr.cpp

line.o: ../rtDaisySP/src/Control/line.cpp ../rtDaisySP/src/Control/line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o line.o ../rtDaisySP/src/Control/line.cpp

phasor.o: ../rtDaisySP/src/Control/phasor.cpp ../rtDaisySP/src/Control/phasor.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o phasor.o ../rtDaisySP/src/Control/phasor.cpp

analogbassdrum.o: ../rtDaisySP/src/Drums/analogbassdrum.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogbassdrum.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o analogbassdrum.o ../rtDaisySP/src/Drums/analogbassdrum.cpp

analogsnaredrum.o: ../rtDaisySP/src/Drums/analogsnaredrum.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/analogsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o analogsnaredrum.o ../rtDaisySP/src/Drums/analogsnaredrum.cpp

hihat.o: ../rtDaisySP/src/Drums/hihat.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/hihat.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hihat.o ../rtDaisySP/src/Drums/hihat.cpp

synthbassdrum.o: ../rtDaisySP/src/Drums/synthbassdrum.cpp ../rtDaisySP/src/Drums/synthbassdrum.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o synthbassdrum.o ../rtDaisySP/src/Drums/synthbassdrum.cpp

synthsnaredrum.o: ../rtDaisySP/src/Drums/synthsnaredrum.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Drums/synthsnaredrum.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o synthsnaredrum.o ../rtDaisySP/src/Drums/synthsnaredrum.cpp

balance.o: ../rtDaisySP/src/Dynamics/balance.cpp ../rtDaisySP/src/Dynamics/balance.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o balance.o ../rtDaisySP/src/Dynamics/balance.cpp

compressor.o: ../rtDaisySP/src/Dynamics/compressor.cpp ../rtDaisySP/src/Dynamics/compressor.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o compressor.o ../rtDaisySP/src/Dynamics/compressor.cpp

crossfade.o: ../rtDaisySP/src/Dynamics/crossfade.cpp ../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o crossfade.o ../rtDaisySP/src/Dynamics/crossfade.cpp

limiter.o: ../rtDaisySP/src/Dynamics/limiter.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Dynamics/limiter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o limiter.o ../rtDaisySP/src/Dynamics/limiter.cpp

autowah.o: ../rtDaisySP/src/Effects/autowah.cpp ../rtDaisySP/src/Effects/autowah.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o autowah.o ../rtDaisySP/src/Effects/autowah.cpp

bitcrush.o: ../rtDaisySP/src/Effects/bitcrush.cpp ../rtDaisySP/src/Effects/bitcrush.h \
		../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bitcrush.o ../rtDaisySP/src/Effects/bitcrush.cpp

chorus.o: ../rtDaisySP/src/Effects/chorus.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/chorus.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o chorus.o ../rtDaisySP/src/Effects/chorus.cpp

decimator.o: ../rtDaisySP/src/Effects/decimator.cpp ../rtDaisySP/src/Effects/decimator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o decimator.o ../rtDaisySP/src/Effects/decimator.cpp

flanger.o: ../rtDaisySP/src/Effects/flanger.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/flanger.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o flanger.o ../rtDaisySP/src/Effects/flanger.cpp

fold.o: ../rtDaisySP/src/Effects/fold.cpp ../rtDaisySP/src/Effects/fold.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fold.o ../rtDaisySP/src/Effects/fold.cpp

overdrive.o: ../rtDaisySP/src/Effects/overdrive.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/overdrive.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o overdrive.o ../rtDaisySP/src/Effects/overdrive.cpp

phaser.o: ../rtDaisySP/src/Effects/phaser.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/phaser.h \
		../rtDaisySP/src/Utility/delayline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o phaser.o ../rtDaisySP/src/Effects/phaser.cpp

reverbsc.o: ../rtDaisySP/src/Effects/reverbsc.cpp ../rtDaisySP/src/Effects/reverbsc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reverbsc.o ../rtDaisySP/src/Effects/reverbsc.cpp

sampleratereducer.o: ../rtDaisySP/src/Effects/sampleratereducer.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Effects/sampleratereducer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sampleratereducer.o ../rtDaisySP/src/Effects/sampleratereducer.cpp

tremolo.o: ../rtDaisySP/src/Effects/tremolo.cpp ../rtDaisySP/src/Effects/tremolo.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tremolo.o ../rtDaisySP/src/Effects/tremolo.cpp

allpass.o: ../rtDaisySP/src/Filters/allpass.cpp ../rtDaisySP/src/Filters/allpass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o allpass.o ../rtDaisySP/src/Filters/allpass.cpp

atone.o: ../rtDaisySP/src/Filters/atone.cpp ../rtDaisySP/src/Filters/atone.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o atone.o ../rtDaisySP/src/Filters/atone.cpp

biquad.o: ../rtDaisySP/src/Filters/biquad.cpp ../rtDaisySP/src/Filters/biquad.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o biquad.o ../rtDaisySP/src/Filters/biquad.cpp

comb.o: ../rtDaisySP/src/Filters/comb.cpp ../rtDaisySP/src/Filters/comb.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o comb.o ../rtDaisySP/src/Filters/comb.cpp

mode.o: ../rtDaisySP/src/Filters/mode.cpp ../rtDaisySP/src/Filters/mode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mode.o ../rtDaisySP/src/Filters/mode.cpp

moogladder.o: ../rtDaisySP/src/Filters/moogladder.cpp ../rtDaisySP/src/Filters/moogladder.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moogladder.o ../rtDaisySP/src/Filters/moogladder.cpp

nlfilt.o: ../rtDaisySP/src/Filters/nlfilt.cpp ../rtDaisySP/src/Filters/nlfilt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nlfilt.o ../rtDaisySP/src/Filters/nlfilt.cpp

svf.o: ../rtDaisySP/src/Filters/svf.cpp ../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o svf.o ../rtDaisySP/src/Filters/svf.cpp

tone.o: ../rtDaisySP/src/Filters/tone.cpp ../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tone.o ../rtDaisySP/src/Filters/tone.cpp

clockednoise.o: ../rtDaisySP/src/Noise/clockednoise.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/clockednoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o clockednoise.o ../rtDaisySP/src/Noise/clockednoise.cpp

grainlet.o: ../rtDaisySP/src/Noise/grainlet.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/grainlet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o grainlet.o ../rtDaisySP/src/Noise/grainlet.cpp

particle.o: ../rtDaisySP/src/Noise/particle.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/particle.h \
		../rtDaisySP/src/Filters/svf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o particle.o ../rtDaisySP/src/Noise/particle.cpp

KarplusString.o: ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/Filters/tone.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o KarplusString.o ../rtDaisySP/src/PhysicalModeling/KarplusString.cpp

drip.o: ../rtDaisySP/src/PhysicalModeling/drip.cpp ../rtDaisySP/src/PhysicalModeling/drip.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drip.o ../rtDaisySP/src/PhysicalModeling/drip.cpp

modalvoice.o: ../rtDaisySP/src/PhysicalModeling/modalvoice.cpp ../rtDaisySP/src/PhysicalModeling/modalvoice.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Noise/dust.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o modalvoice.o ../rtDaisySP/src/PhysicalModeling/modalvoice.cpp

pluck.o: ../rtDaisySP/src/PhysicalModeling/pluck.cpp ../rtDaisySP/src/PhysicalModeling/pluck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pluck.o ../rtDaisySP/src/PhysicalModeling/pluck.cpp

resonator.o: ../rtDaisySP/src/PhysicalModeling/resonator.cpp ../rtDaisySP/src/PhysicalModeling/resonator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o resonator.o ../rtDaisySP/src/PhysicalModeling/resonator.cpp

stringvoice.o: ../rtDaisySP/src/PhysicalModeling/stringvoice.cpp ../rtDaisySP/src/PhysicalModeling/stringvoice.h \
		../rtDaisySP/src/Filters/svf.h \
		../rtDaisySP/src/PhysicalModeling/KarplusString.h \
		../rtDaisySP/src/Dynamics/crossfade.h \
		../rtDaisySP/src/Utility/dcblock.h \
		../rtDaisySP/src/Utility/delayline.h \
		../rtDaisySP/src/Filters/tone.h \
		../rtDaisySP/src/Noise/dust.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stringvoice.o ../rtDaisySP/src/PhysicalModeling/stringvoice.cpp

blosc.o: ../rtDaisySP/src/Synthesis/blosc.cpp ../rtDaisySP/src/Synthesis/blosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o blosc.o ../rtDaisySP/src/Synthesis/blosc.cpp

fm2.o: ../rtDaisySP/src/Synthesis/fm2.cpp ../rtDaisySP/src/Synthesis/fm2.h \
		../rtDaisySP/src/Synthesis/oscillator.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fm2.o ../rtDaisySP/src/Synthesis/fm2.cpp

formantosc.o: ../rtDaisySP/src/Synthesis/formantosc.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/formantosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o formantosc.o ../rtDaisySP/src/Synthesis/formantosc.cpp

oscillator.o: ../rtDaisySP/src/Synthesis/oscillator.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/oscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o oscillator.o ../rtDaisySP/src/Synthesis/oscillator.cpp

oscillatorbank.o: ../rtDaisySP/src/Synthesis/oscillatorbank.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/oscillatorbank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o oscillatorbank.o ../rtDaisySP/src/Synthesis/oscillatorbank.cpp

variablesawosc.o: ../rtDaisySP/src/Synthesis/variablesawosc.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/variablesawosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o variablesawosc.o ../rtDaisySP/src/Synthesis/variablesawosc.cpp

variableshapeosc.o: ../rtDaisySP/src/Synthesis/variableshapeosc.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/variableshapeosc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o variableshapeosc.o ../rtDaisySP/src/Synthesis/variableshapeosc.cpp

vosim.o: ../rtDaisySP/src/Synthesis/vosim.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/vosim.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vosim.o ../rtDaisySP/src/Synthesis/vosim.cpp

zoscillator.o: ../rtDaisySP/src/Synthesis/zoscillator.cpp ../rtDaisySP/src/Utility/dsp.h \
		../rtDaisySP/src/Synthesis/zoscillator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o zoscillator.o ../rtDaisySP/src/Synthesis/zoscillator.cpp

dcblock.o: ../rtDaisySP/src/Utility/dcblock.cpp ../rtDaisySP/src/Utility/dcblock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dcblock.o ../rtDaisySP/src/Utility/dcblock.cpp

jitter.o: ../rtDaisySP/src/Utility/jitter.cpp ../rtDaisySP/src/Utility/jitter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o jitter.o ../rtDaisySP/src/Utility/jitter.cpp

metro.o: ../rtDaisySP/src/Utility/metro.cpp ../rtDaisySP/src/Utility/metro.h \
		../rtDaisySP/src/Utility/dsp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o metro.o ../rtDaisySP/src/Utility/metro.cpp

port.o: ../rtDaisySP/src/Utility/port.cpp ../rtDaisySP/src/Utility/port.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o port.o ../rtDaisySP/src/Utility/port.cpp
