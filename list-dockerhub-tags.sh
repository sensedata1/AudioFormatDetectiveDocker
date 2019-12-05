curl -s -S \
  "https://registry.hub.docker.com/v2/repositories/sensedata1/audioformatdetective/tags/" \
  | jq '."results"[]["name"]'
