// script.js

// Function to calculate the GCD (Greatest Common Divisor) or HCF using the Euclidean algorithm
function gcd(a, b) {
  return b === 0 ? a : gcd(b, a % b);
}

// Function to calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

// Function to handle the LCM calculation
function calculateLCM() {
  let num1 = parseInt(document.getElementById("num1").value);
  let num2 = parseInt(document.getElementById("num2").value);

  if (isNaN(num1) || isNaN(num2)) {
    displayResult("Please enter valid numbers!");
    return;
  }

  let result = lcm(num1, num2);
  displayResult(`LCM of ${num1} and ${num2} is ${result}`);
}

// Function to handle the HCF calculation
function calculateHCF() {
  let num1 = parseInt(document.getElementById("num1").value);
  let num2 = parseInt(document.getElementById("num2").value);

  if (isNaN(num1) || isNaN(num2)) {
    displayResult("Please enter valid numbers!");
    return;
  }

  let result = gcd(num1, num2);
  displayResult(`HCF of ${num1} and ${num2} is ${result}`);
}

// Function to display the result with animation
function displayResult(message) {
  let resultDiv = document.getElementById("result");
  resultDiv.innerHTML = `<span>${message}</span>`;
}
