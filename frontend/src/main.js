import { createAcquisitionChart } from './charts';

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

let hero_select = document.getElementById("hero")
let hero_portrait = document.getElementById("hero-img")

if (hero_select && hero_portrait) {
    hero_select.onchange = (e) => {
        hero_portrait.style.opacity = '0';

        setTimeout(() => {
          const selectedHero = hero_select.value;
          const newSrc = heroImages[selectedHero];
          hero_portrait.src = newSrc;
            hero_portrait.style.opacity = '1';
        }, 100); // Adjusted timeout to match a typical fade duration
    }
}
document.addEventListener('DOMContentLoaded', async () => {
    await createAcquisitionChart(); // Ensure the DOM is fully loaded before invoking
})
