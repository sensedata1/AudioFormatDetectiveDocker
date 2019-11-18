# AudioFormatDetective
Simple utility for reviewers
Uses audiotools and eyed3 to evaluate the attributes of audio files uploaded to the music library and checks them against the prerequisites. 

-- now integrated the Lossless Audio checker and watermark detection using the speechrecognition module. 
Prints [ok] or [ERROR] depending on how they evaluate. 

After feeding it hundreds of files, some valid, some corrupt, I think I've managed to catch most of the exceptions and allow it to keep chugging along happily.

Requires
 audiotools
 eyeD3
 zipFile
 
 

Note, This won't be of much use to many folks as it is as this is looking for
WAV files with the following spec:

44100kHz sample frequency
16bits per sample
Stereo channels			

and MP3 files with the following spec:

444100 sample frequency
16bits per sample
320kbps cbr bitrate

Although it's easily modified.

The onefile dist runs fine on my Mac

To run the --onefile version which contains all dependencies, grab one from the /dist folder, grab the LAC script and place that in your user home directory. chmod a+x both scripts and run the AudioFileDetective* file in Terminal. Drag in your downloads folder and you're set. --UPDATE: dependency ffmpeg must now be installed in the host system. Easy way is to install homebrew then "brew install ffmpeg"

The *LLZ version will not unzip archives for you, and is set to execute on_created when a file is created in the downloads folder of your choosing. ie when you unzip the file manually which has downloaded.

The *L version unzips downloaded archives automatically and processes when the on_moved condition is met. ie when a file completes downloading in to the chosen folder. 	
