#ifndef GF1_SOUND_H
#define GF1_SOUND_H
//****************************************************************************
//**
//**    GF1_Sound.h
//**
//**    Copyright (c) 2003 QANTM Australia CMC Pty Ltd
//**
//**    Author:  Dale Freya
//**    Created: 18/11/2003
//**
//****************************************************************************
#include <GF1_Def.h>


   namespace GF1
   {
      // =====================================================================
      // Sound
      // =====================================================================
      // This class represents a PCM (Pulse Code Modulated) or compressed
      // sound file.  Such as .WAV, .MP2, .MP3, .OGG or .RAW.
      // =====================================================================
      struct SoundImpl;

      class GF1_API Sound
      {
      public:
         static const int MIN_FREQUENCY;
         static const int MAX_FREQUENCY;

         //-------------------------------------------------------------------
         // Constructor
         //-------------------------------------------------------------------
         // Creates a sample.  When created the sample is not playing.
         //
         // sampleFileName
         //    Filename/path of the sample.
         // streamed
         //    Do you want the sample streamed from disk instead of being 
         //    loaded entirely into memory.
         //-------------------------------------------------------------------
         Sound(const char *sampleFileName, bool streamed = false);


         //-------------------------------------------------------------------
         // Copy Constructor
         //-------------------------------------------------------------------
         // rhs
         //    The sample being copied.
         //-------------------------------------------------------------------
         Sound(const Sound &rhs);


         //-------------------------------------------------------------------
         // Destructor
         //-------------------------------------------------------------------
         ~Sound();


         //-------------------------------------------------------------------
         // Bad
         //-------------------------------------------------------------------
         // Returns true if the sample failed to load.
         //-------------------------------------------------------------------
         bool Bad() const;


         //-------------------------------------------------------------------
         // GetFileName
         //-------------------------------------------------------------------
         // Returns the filename of the sample.
         //-------------------------------------------------------------------
         const char *GetFileName() const;


         //-------------------------------------------------------------------
         // IsPlaying
         //-------------------------------------------------------------------
         // Returns true if the sample is currently playing.
         //-------------------------------------------------------------------
         bool IsPlaying() const;


         //-------------------------------------------------------------------
         // IsLooped
         //-------------------------------------------------------------------
         // Returns true if the sample is looped.
         //-------------------------------------------------------------------
         bool IsLooped() const;


         //-------------------------------------------------------------------
         // IsStreaming
         //-------------------------------------------------------------------
         // Returns true if the sample is streaming from disk.
         //-------------------------------------------------------------------
         bool IsStreaming() const;


         //-------------------------------------------------------------------
         // IsPaused
         //-------------------------------------------------------------------
         // Returns true if the sample is paused.
         //-------------------------------------------------------------------
         bool IsPaused() const;


         // ------------------------------------------------------------------
         // GetFrequency
         // ------------------------------------------------------------------
         // Returns the frequency in HZ of the sample.
         // ------------------------------------------------------------------
         int GetFrequency() const;


         //-------------------------------------------------------------------
         // Play
         //-------------------------------------------------------------------
         // Play the sample.
         //-------------------------------------------------------------------
         void Play();


         //-------------------------------------------------------------------
         // Stop
         //-------------------------------------------------------------------
         // Stop the sample.
         //-------------------------------------------------------------------
         void Stop();


         //-------------------------------------------------------------------
         // Pause
         //-------------------------------------------------------------------
         // Pause or unpause the sound.
         //-------------------------------------------------------------------
         void Pause(bool pause);


         //-------------------------------------------------------------------
         // SetLooped
         //-------------------------------------------------------------------
         // Specify whether the sample should be looped or not.
         //
         // looped
         //    true if the sample should be looped, otherwise false.
         //-------------------------------------------------------------------
         void SetLooped(bool looped);


         //-------------------------------------------------------------------
         // SetFrequency
         //-------------------------------------------------------------------
         // Sets the sample's frequency or playback rate, in HZ.
         //
         // frequency
         //    The frequency to set. 
         //    Valid ranges are from 100 to 705600
         //-------------------------------------------------------------------
         void SetFrequency(int frequency);

      private:
         SoundImpl *m_impl;
      };

   }  // end namespace GF1


//****************************************************************************
//**
//**   END INTERFACE
//**
//****************************************************************************
#endif
