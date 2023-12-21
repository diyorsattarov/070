const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
    res.send(`
        <form action="/submit-data" method="post">
            <textarea name="jsonData" rows="10" cols="50" placeholder='Enter JSON data'></textarea><br>
            <input type="submit" value="Submit">
        </form>
    `);
});

app.post('/submit-data', (req, res) => {
    console.log('Received JSON:', req.body.jsonData);
    res.redirect(307, 'http://localhost:8080/submit-data');
});


app.listen(port, () => {
    console.log(`Express server running on http://localhost:${port}`);
});
