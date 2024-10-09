#!/bin/bash
read -p "Enter the file name to upload : " fname
base64 $fname > $fname.b64
{"message": "uploaded $fname", "content": ""}
CONTENT=$(cat $fname.b64)
echo "{\"message\": \"uploaded $fname\", \"content\": \"$CONTENT\"}" > payload.json

curl -X PUT -H "Authorization: token " \-H "Content-Type: application/json" \--data @payload.json \https://api.github.com/repos/Irfan-Fareeth/testlab/contents/$fname
