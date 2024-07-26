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

const heroImages = {
    ashe: asheImage,
    cassidy: cassidyImage,
    hanzo: hanzoImage,
    sojourn: sojournImage,
    soldier76: soldier76Image,
    tracer: tracerImage,
    widowmaker: widowmakerImage
}
console.log("hello")
let player_data = null;
let battletag = null;
let player_call = false;
let selectedHero = "ashe";
let hero_select = document.getElementById("hero");
let hero_portrait = document.getElementById("hero-img");
change_hero_stats("ashe");
if (hero_select && hero_portrait) {
    hero_select.onchange = async (e) => {
        for (let i = 0; i < 4; i++) {
            const canvas = document.getElementById(`myChart${i}`);
            canvas.style.display = 'none';
        }
        hero_portrait.style.opacity = '0';
        setTimeout(() => {
            selectedHero = hero_select.value;
            const newSrc = heroImages[selectedHero];
            hero_portrait.src = newSrc;
            hero_portrait.style.opacity = '1';
            change_hero_stats(selectedHero);
            if (player_data && battletag) {
                setTimeout(() => {
                    update_hero_stats(battletag, player_data, selectedHero);
                    player_call = true;
                }, 300)
            }
        }, 100);
    }
}

let text_input = document.getElementById("battletag");
const submit_btn = document.getElementById("submit-btn");
let warning_notif = document.getElementById("playtime");
let spinner = document.getElementById("loader");
submit_btn.onclick = async (e) => {
    e.preventDefault();
    battletag = text_input.value
    if (!player_call) {
        try {
            if (battletag.length >= 8) {
                player_call = true;
                spinner.style.visibility = ("visible")
                battletag = battletag.split('#').join('-');
                player_data = await get_player_stat(battletag);
                await change_hero_stats(selectedHero);
                await update_hero_stats(battletag, player_data, selectedHero);
                spinner.style.visibility = ("hidden")
            } else {
                console.log("INVALID BTAG! :(");
            }
        } catch (e) {
            //warning_notif.innerHTML = `Not enough playtime/data for this hero`;
            spinner.style.visibility = ("hidden")
        }
    }
    setTimeout(() => {
        player_call = false;
    }, 500)
}

async function update_hero_stats(btag_ID, player_data, hero_name) {
    const hero = heroes[hero_name];
    console.log(player_data);
    updateAllCharts(btag_ID, player_data[hero_name], "#39FF1480", hero);
}

async function change_hero_stats(hero_name) {
    const hero = heroes[hero_name];
    for (let i = 0; i < hero.len; i++) {
        if (hero[i].length == 2) {
            await fetch_data_and_create_scatter_plot(`myChart${i}`, hero.name, hero[i][0], hero[i][1], hero.color);
        }
        else if (hero[i].length == 1) {
            await fetch_data_and_create_bar_chart(`myChart${i}`, hero.name, hero[i][0], hero.color);
        }
    }
}
