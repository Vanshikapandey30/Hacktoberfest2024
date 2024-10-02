// Function to calculate logarithm
function calculateLog() {
    let number = parseFloat(document.getElementById("number").value);
    let base = parseFloat(document.getElementById("base").value) || 10; // Default base is 10

    if (isNaN(number) || number <= 0) {
        alert("Please enter a valid positive number");
        return;
    }

    if (isNaN(base) || base <= 0) {
        alert("Please enter a valid positive base");
        return;
    }

    let logResult = Math.log(number) / Math.log(base);
    
    // Display log result with animation
    let logResultElement = document.getElementById("log-result");
    logResultElement.innerText = `Log Result: ${logResult.toFixed(4)}`;
    logResultElement.style.opacity = "1";

    // Trigger the bounce animation
    applyBounceAnimation(logResultElement);
}

// Function to calculate antilogarithm
function calculateAntilog() {
    let number = parseFloat(document.getElementById("number").value);
    let base = parseFloat(document.getElementById("base").value) || 10; // Default base is 10

    if (isNaN(number)) {
        alert("Please enter a valid number");
        return;
    }

    let antilogResult = Math.pow(base, number);
    
    // Display antilog result with animation
    let antilogResultElement = document.getElementById("antilog-result");
    antilogResultElement.innerText = `Antilog Result: ${antilogResult.toFixed(4)}`;
    antilogResultElement.style.opacity = "1";

    // Trigger the bounce animation
    applyBounceAnimation(antilogResultElement);
}

// Function to apply bounce animation
function applyBounceAnimation(element) {
    element.classList.remove('bounce'); // Reset the animation
    void element.offsetWidth; // Trigger reflow (restarting the animation)
    element.classList.add('bounce'); // Reapply the animation
}
