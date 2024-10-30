const arrayContainer = document.getElementById("array-container");
const array = [];
const arraySize = 30;
const delay = 100; // Delay in ms for visualization

// Generate random array and display as bars
function generateArray() {
    arrayContainer.innerHTML = "";
    for (let i = 0; i < arraySize; i++) {
        const value = Math.floor(Math.random() * 300) + 10;
        array.push(value);

        const bar = document.createElement("div");
        bar.classList.add("array-bar");
        bar.style.height = `${value}px`;
        arrayContainer.appendChild(bar);
    }
}

async function sortArray() {
    for (let i = 0; i < array.length; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            const bars = document.getElementsByClassName("array-bar");
            bars[j].style.backgroundColor = "red";
            bars[j + 1].style.backgroundColor = "red";

            if (array[j] > array[j + 1]) {
                [array[j], array[j + 1]] = [array[j + 1], array[j]];

                bars[j].style.height = `${array[j]}px`;
                bars[j + 1].style.height = `${array[j + 1]}px`;
            }

            await new Promise(resolve => setTimeout(resolve, delay));

            bars[j].style.backgroundColor = "#4CAF50";
            bars[j + 1].style.backgroundColor = "#4CAF50";
        }
    }
}

generateArray();
