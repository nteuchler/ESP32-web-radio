// radioStations.h

// Definer radiostationernes stream-links
#define radioViElsker          "http://netradio.skala.fm/vielsker"
#define radioGrandPrix         "https://netradio.vlr.dk/popup2"
#define radioClassicRock       "https://netradio.vlr.dk/classicrock"
#define radioClassicSoftHits   "https://netradio.vlr.dk/clasoft"
#define radioClassicDanskeHits "https://netradio.vlr.dk/cladk"
#define radioDansktop          "http://80.63.11.119/dansktop"

#define radioDRP1 "http://live-icy.gss.dr.dk:8000/A/A03H.mp3"
#define radioDRP3 "http://live-icy.gss.dr.dk:8000/A/A05H.mp3"
#define radioDRP4 "http://live-icy.gss.dr.dk:8000/A/A15L.mp3"
#define radioDRKlassisk "http://live-icy.gss.dr.dk:8000/A/A04H.mp3"
#define radioDRP6 "http://live-icy.gss.dr.dk:8000/A/A29H.mp3"

#define radioGlobusGuld "https://stream.probroadcast.dk/guldesbjerg"
#define radioNOVA       "http://stream.novafm.dk/nova128.mp3"
#define radioPopFM      "http://stream.popfm.dk/pop128.mp3"
#define radioVLR        "http://netradio.vlr.dk/vlr8d"
#define radioRadio4     "https://27993.live.streamtheworld.com/RADIO4.mp3"
#define radioSkalaFM    "http://netradio.skala.fm/ska8d"

// Opret en liste over radiostationerne
const char* radioListe[] = {
  radioViElsker,
  radioGrandPrix,
  radioClassicRock,
  radioClassicSoftHits,
  radioClassicDanskeHits,
  radioDansktop,
  radioDRP1,
  radioDRP3,
  radioDRP4,
  radioDRKlassisk,
  radioDRP6,
  radioGlobusGuld,
  radioNOVA,
  radioPopFM,
  radioVLR,
  radioRadio4,
  radioSkalaFM
};

const char* radioListeText[] = {
  "radio Vi Elsker",
  "radio GrandPrix",
  "Classic Rock",
  "Classic Soft Hits",
  "Classic Danske Hits",
  "Dansktop",
  "P et",
  "P3",
  "P4",
  "DR Klassisk",
  "P6",
  "Globus Guld",
  "Nova",
  "Pop F M",
  "VLR",d
  "Radio 4",
  "Skala F M!"
};


const int radioListeLength = sizeof(radioListe) / sizeof(radioListe[0]); // Antal stationer i listen
