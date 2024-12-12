// Function to calculate the HCF (GCD) of two numbers
function hcf(num1, num2) {
    while (num2 !== 0) {
        let temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

// Function to calculate the LCM of two numbers
function lcm(num1, num2) {
    return (num1 * num2) / hcf(num1, num2);
}

// Function to calculate HCF of multiple numbers
function calculateHCF(numbers) {
    return numbers.reduce((acc, num) => hcf(acc, num));
}

// Function to calculate LCM of multiple numbers
function calculateLCM(numbers) {
    return numbers.reduce((acc, num) => lcm(acc, num));
}

// Function to dynamically add more input fields
document.getElementById('add-number').addEventListener('click', () => {
    const container = document.getElementById('input-container');
    const inputDiv = document.createElement('div');
    inputDiv.classList.add('number-input');
    inputDiv.innerHTML = '<input type="number" placeholder="Number">';
    container.appendChild(inputDiv);
});

// Main function to calculate and display the HCF and LCM for n numbers
// Main function to calculate and display the HCF and LCM for n numbers
function calculate() {
    const inputs = document.querySelectorAll('#input-container input');
    let numbers = [];

    inputs.forEach(input => {
        const value = parseInt(input.value);
        if (!isNaN(value) && value > 0) {
            numbers.push(value);
        }
    });

    if (numbers.length < 2) {
        alert("Please enter at least two valid positive numbers");
        return;
    }

    let hcfValue = calculateHCF(numbers);
    let lcmValue = calculateLCM(numbers);

    // Update the HTML with colored and bold results
    document.getElementById("hcf-result").innerHTML = 
        "HCF: <span class='result-value'>" + hcfValue + "</span>";
    document.getElementById("lcm-result").innerHTML = 
        "LCM: <span class='result-value'>" + lcmValue + "</span>";
}

