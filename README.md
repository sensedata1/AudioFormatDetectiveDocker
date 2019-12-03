# AudioFormatDetective
Simple utility for AudioJungle reviewers
Uses audiotools and eyed3 to evaluate the attributes of audio files uploaded to the music library and checks them against the prerequisites. 

---

---

To run you must have Docker installed, then:

` docker run --name afd -v <DOWNLOADS_FOLDER_PATH>:/AJTEMP sensedata1/audioformatdetective:63 `

To stop:

`docker stop afd `

To restart:

`docker start afd`


