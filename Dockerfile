FROM python:3.8 AS build

COPY . /app
WORKDIR /app
RUN apt-get update && apt-get install -y \
apt-utils \
libcdio-utils \
python-pyaudio \
python3-pyaudio \
make \
python-setuptools \
ffmpeg \
&& rm -rf /var/lib/apt/lists/*

RUN chmod a+x docker-build-script.sh \
&& ./docker-build-script.sh \
&& mkdir /AJTEMP \
&& chmod a+x /app/dist/AudioFormatDetectiveCON

WORKDIR /app/dist

FROM python:3.8-slim AS production

RUN apt-get update && apt-get install -y --no-install-recommends \
apt-utils \
ffmpeg \
&& mkdir /AJTEMP \
&& mkdir /app \
&& rm -rf /var/lib/apt/lists/* \
&& rm -rf /tmp/*
WORKDIR /app

COPY --from=build /app/dist/AudioFormatDetectiveCON .

RUN chmod a+x AudioFormatDetectiveCON
RUN apt-get update
RUN apt-get install -y libmagic1
RUN chmod a+x AudioFormatDetectiveCON

CMD ["/app/AudioFormatDetectiveCON"]

