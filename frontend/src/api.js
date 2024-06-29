import axios from 'axios'

export async function get_hero_stat(heroName, columnData) {
    try {
        const response = await axios.get('http://0.0.0.0:3000/api/hero_stat', {
            params: {
                hero_name: heroName,
                column: columnData
            }
        });
        return response.data; // ensure this value is returned to the caller
    } catch (error) {
        console.error(error);
        return null; // Handle error cases or return an error indicator
    }
}

let warning_notif = document.getElementById("playtime");
export async function get_player_stat(btag) {
    try{
        const response = await axios.get('http://0.0.0.0:3000/api/player', {
            params: {
                battletag: btag
            }
        });
        return response.data;
    } catch (e) {
        warning_notif.innerHTML = `player '${btag}' not found or profile is private`;
        warning_notif.style.visibility = ("visible")
    }
}