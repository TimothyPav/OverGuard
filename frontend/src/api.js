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

export async function get_player_stat(btag) {
    console.log("WE R IN THE FUNCTION GET_PLAYER_STAT");
    try{
        const response = await axios.get('http://0.0.0.0:3000/api/player', {
            params: {
                battletag: btag
            }
        });
        //console.log(response.data);
        return response.data;
    } catch (e) {
        console.log("player not found: ", e);
    }
}