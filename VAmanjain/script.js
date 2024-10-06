// DOM elements
const inputContainer = document.getElementById('input-container');
const addNumberBtn = document.getElementById('add-number');
const calculateBtn = document.getElementById('calculate-btn');
const lcmResult = document.getElementById('lcmResult');
const hcfResult = document.getElementById('hcfResult');

// Add new input field
addNumberBtn.addEventListener('click', () => {
  const inputGroup = createInputGroup();
  inputContainer.appendChild(inputGroup);
  updateRemoveButtons();
});

// Create input group
function createInputGroup() {
  const inputGroup = document.createElement('div');
  inputGroup.className = 'input-group fade-in';
  
  const input = document.createElement('input');
  input.type = 'number';
  input.className = 'num';
  input.placeholder = 'Enter a number';
  input.required = true;
  
  const removeBtn = document.createElement('button');
  removeBtn.className = 'remove-number';
  removeBtn.innerHTML = '<i class="fas fa-times"></i>';
  removeBtn.onclick = () => removeInput(inputGroup);
  
  inputGroup.appendChild(input);
  inputGroup.appendChild(removeBtn);
  return inputGroup;
}

// Remove input field
function removeInput(inputGroup) {
  inputGroup.classList.add('fade-out');
  setTimeout(() => {
    inputContainer.removeChild(inputGroup);
    updateRemoveButtons();
  }, 300);
}

// Update remove buttons state
function updateRemoveButtons() {
  const removeButtons = document.querySelectorAll('.remove-number');
  removeButtons.forEach(btn => {
    btn.disabled = removeButtons.length <= 2;
  });
}

// Calculate LCM and HCF
calculateBtn.addEventListener('click', () => {
  const numbers = Array.from(document.getElementsByClassName('num'))
    .map(input => parseInt(input.value))
    .filter(num => !isNaN(num));

  if (numbers.length < 2) {
    alert('Please enter at least two valid numbers.');
    return;
  }

  const lcm = calculateLCM(numbers);
  const hcf = calculateHCF(numbers);

  animateResult(lcmResult, lcm);
  animateResult(hcfResult, hcf);
  
  // Animate calculate button
  calculateBtn.classList.add('pulse');
  setTimeout(() => calculateBtn.classList.remove('pulse'), 500);
});

// Animate result display
function animateResult(element, value) {
  element.textContent = '';
  element.classList.remove('fade-in');
  void element.offsetWidth; // Trigger reflow
  element.classList.add('fade-in');
  element.textContent = value;
}

// Calculate LCM
function calculateLCM(numbers) {
  return numbers.reduce((a, b) => Math.abs(a * b) / calculateHCF([a, b]));
}

// Calculate HCF
function calculateHCF(numbers) {
  return numbers.reduce((a, b) => {
    while (b !== 0) {
      let t = b;
      b = a % b;
      a = t;
    }
    return a;
  });
}

// Initialize remove buttons
updateRemoveButtons();