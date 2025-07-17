#!/usr/bin/node
const https = require('https');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

https.get(filmUrl, (res) => {
  let data = '';

  res.on('data', (chunk) => { data += chunk; });
  res.on('end', async () => {
    const film = JSON.parse(data);
    const characters = film.characters;

    for (const url of characters) {
      await new Promise((resolve) => {
        https.get(url, (res) => {
          let characterData = '';
          res.on('data', (chunk) => { characterData += chunk; });
          res.on('end', () => {
            const character = JSON.parse(characterData);
            console.log(character.name);
            resolve();
          });
        });
      });
    }
  });
}).on('error', (err) => {
  console.error(`Error: ${err.message}`);
});
