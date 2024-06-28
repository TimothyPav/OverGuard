import axios from 'axios'

export async function get_hero_stat(heroName, columnData) {
    try {
        const response = await axios.get('http://0.0.0.0:3000/api/hero_stat', {
            params: {
                hero_name: heroName,
                column: columnData
            }
        });
        //console.log(response.data); // to check what you get back
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
        //console.log(response.data);
        return response.data;
    } catch (e) {
        warning_notif.innerHTML = `Player with battletag '${battletag}' not found or profile is private`;
        warning_notif.style.visibility = ("visible")
    }
}