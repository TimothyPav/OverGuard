import { fetch_data_and_create_bar_chart, fetch_data_and_create_scatter_plot, addData, removeData, updateAllCharts } from './charts';
import { widowmaker, ashe, tracer, soldier76, sojourn, cassidy, hanzo, heroes } from './hero_objects.js';
import { get_player_stat } from './api.js';

import asheImage from '../assets/images/ashe.png';
import cassidyImage from '../assets/images/cassidy.png';
import hanzoImage from '../assets/images/hanzo.png';
import sojournImage from '../assets/images/sojourn.png';
import soldier76Image from '../assets/images/soldier76.png';
import tracerImage from '../assets/images/tracer.png';
import widowmakerImage from '../assets/images/widowmaker.png';

// Map these imports to hero names
const heroImages = {
    ashe: asheImage,
    cassidy: cassidyImage,
    hanzo: hanzoImage,
    sojourn: sojournImage,
    soldier76: soldier76Image,
    tracer: tracerImage,
    widowmaker: widowmakerImage
};

let player_data = null;
let hero_select = document.getElementById("hero");
let hero_portrait = document.getElementById("hero-img");
change_hero_stats("ashe");
if (hero_select && hero_portrait) {
    hero_select.onchange = (e) => {
        for (let i = 0; i < 4; i++) {
            const canvas = document.getElementById(`myChart${i}`);
            canvas.style.display = 'none';
        }
        hero_portrait.style.opacity = '0';

        setTimeout(() => {
            const selectedHero = hero_select.value;
            const newSrc = heroImages[selectedHero];
            hero_portrait.src = newSrc;
            hero_portrait.style.opacity = '1';
            change_hero_stats(selectedHero);
        }, 100); // Adjusted timeout to match a typical fade duration
        //change_hero_stats(ashe);

    }
}

let text_input = document.getElementById("battletag");
const submit_btn = document.getElementById("submit-btn");
submit_btn.onclick = async (e) => {
    e.preventDefault();
    const btag = text_input.value
    try {
        console.log("btag: ", btag);
        console.log("len: ", btag.length);
        if (btag.length >= 8) {
            player_data = await get_player_stat(btag);
            update_hero_stats(btag, player_data, "ashe");
        } else {
            console.log("INVALID BTAG! :(");
        }
    } catch (e) {
        console.log("INVALID BTAG!", e);
    }
}

async function update_hero_stats(btag_ID, player_data, hero_name){
    const hero = heroes[hero_name];
    for(let i=0; i< hero.len; i++){
        if (hero[i].length == 2) {
            //addData(`myChart${i}`, `test:`, player_data, "green");
            updateAllCharts("test label", player_data, "blue");
        }
        else if (hero[i].length == 1) {

        }
    }
}

async function change_hero_stats(hero_name) {
    //console.log("hero name: ", hero_name.name);
    const hero = heroes[hero_name];
    for (let i = 0; i < hero.len; i++) {
        //console.log(hero[i].length)
        if (hero[i].length == 2) {
            await fetch_data_and_create_scatter_plot(`myChart${i}`, hero.name, hero[i][0], hero[i][1], hero.color);
        }
        else if (hero[i].length == 1) {
            await fetch_data_and_create_bar_chart(`myChart${i}`, hero.name, hero[i][0], hero.color);
        }
    }
}