import Chart from 'chart.js/auto';
import { get_hero_stat } from './api.js';
Chart.defaults.color = "#000000";
Chart.defaults.font.size = 14;

const chartInstances = {};

export async function fetch_data_and_create_scatter_plot(id, heroName, columnDataX, columnDataY, color) {
  try {
    const [xResponse, yResponse] = await Promise.all([
      get_hero_stat(heroName, columnDataX),
      get_hero_stat(heroName, columnDataY)
    ]);

    const xData = xResponse[heroName][columnDataX];
    const yData = yResponse[heroName][columnDataY];

    // Ensure both datasets are loaded and contain data
    if (!xData || !yData) {
      console.error('Data for one of the stats is missing or invalid');
      return;
    }

    // Merge data based on player names
    const mergedData = Object.keys(xData).map(player => {
      return {
        x: xData[player],
        y: yData[player] || null,  // Include 'y' value if found, otherwise use null
        name: player
      };
    });

    createChart(id, mergedData, columnDataX, columnDataY, color);
  } catch (error) {
    console.error('Error loading or processing data:', error);
  }
}

function createChart(id, data, columnDataX, columnDataY, color) {
  const canvas = document.getElementById(id);
  const ctx = canvas.getContext('2d');

  const width = canvas.width;
  const height = canvas.height;

  // Destroy the existing chart instance if it exists
  if (chartInstances[id]) {
    chartInstances[id].destroy();
    ctx.clearRect(0, 0, width, height); // Clear the canvas after destroying the chart
  }
  canvas.style.display = 'block';
  chartInstances[id] = new Chart(ctx, {
    type: 'scatter',
    data: {
      datasets: [{
        label: `${columnDataX} vs. ${columnDataY}`,
        data: data,
        backgroundColor: data.map(() => color),
        pointRadius: 7,
        pointHoverRadius: 10,
      }]
    },
    options: {
      scales: {
        x: {
          title: {
            display: true,
            text: columnDataX
          }
        },
        y: {
          title: {
            display: true,
            text: columnDataY
          }
        }
      },
      plugins: {
        tooltip: {
          callbacks: {
            label: function (context) {
              const point = context.raw;
              return `${point.name}: ${point.x} ${columnDataX}, ${point.y} ${columnDataY}`;
            }
          }
        }
      }
    }
  });
}

export async function fetch_data_and_create_bar_chart(id, hero_name, columnDataY, color) {
  try {
    const columnData = await get_hero_stat(hero_name, columnDataY);
    const data = columnData[hero_name][columnDataY];
    console.log(data);
    if (!data) {
      console.error('Data is missing or invalid');
      return;
    }

    const mergedData = Object.keys(data).map(player => {
      return {
        y: data[player],
        x: player
      };
    });

    createBarChart(id, hero_name, mergedData, columnDataY, color)

  } catch (e) {
    console.log("Error loading or processing data:", e);
  }
}

function createBarChart(id, hero_name, data, columnData, color) {
  const canvas = document.getElementById(id);
  const ctx = canvas.getContext('2d');

  const width = canvas.width;
  const height = canvas.height;

  // Destroy the existing chart instance if it exists
  if (chartInstances[id]) {
    chartInstances[id].destroy();
    ctx.clearRect(0, 0, width, height); // Clear the canvas after destroying the chart
  }
  canvas.style.display = 'block';

  chartInstances[id] = new Chart(ctx, {
    type: 'bar',
    data: {
      datasets: [{
        label: `Individual player vs. ${columnData}`,
        data: data,
        backgroundColor: color,
      }]
    },
    options: {
      scales: {
        x: {
          ticks: {
            display: false //this will remove only the label
       }
        },
        y: {
          beginAtZero: true,
          title: {
            display: true,
            text: columnData
          }
        }
      }
    }
  });
}

export function updateAllCharts(label, newData, newColor) {
  Object.keys(chartInstances).forEach((chartId) => {
    const chart = chartInstances[chartId];
    // Assume you have a function to fetch new data specific for this chart
    addData(chart, label, newData, newColor);
  });
}

export function addData(chart, label, newData, newColor) {
  // Adding the new label to the chart
  chart.data.labels.push(label);

  // Adding new data and specifying color for each dataset
  chart.data.datasets.forEach((dataset) => {
      dataset.data.push(newData);
      // Append new color or default to last color used if newColor is not specified
      dataset.backgroundColor.push(newColor || dataset.backgroundColor[dataset.backgroundColor.length - 1]);
  });

  // Update the chart to reflect the changes
  chart.update();
}

export function removeData(chartID) {
  const chart = document.getElementById(chartID);
  chart.data.labels.pop();
  chart.data.datasets.forEach((dataset) => {
      dataset.data.pop();
  });
  chart.update();
}