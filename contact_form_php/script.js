document.getElementById('contactForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent form from submitting normally
  
    // Get form values
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const message = document.getElementById('message').value;
  
    // Clear previous error messages
    document.getElementById('nameError').innerText = '';
    document.getElementById('emailError').innerText = '';
    document.getElementById('messageError').innerText = '';
    document.getElementById('successMessage').innerText = '';
  
    // AJAX request to PHP script
    const xhr = new XMLHttpRequest();
    xhr.open('POST', 'process_form.php', true);
    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
      if (xhr.status === 200) {

        const response = JSON.parse(xhr.responseText);
  
        // Display success message or error messages
        if (response.success) {
          document.getElementById('successMessage').innerText = 'Form submitted successfully!';
          document.getElementById('contactForm').reset(); // Clear the form
        } else {
          if (response.errors.name)document.getElementById('nameError').innerText = response.errors.name;
          if (response.errors.email) document.getElementById('emailError').innerText = response.errors.email;
          if (response.errors.message) document.getElementById('messageError').innerText = response.errors.message;
        }
      }
    };
    xhr.send(`name=${encodeURIComponent(name)}&email=${encodeURIComponent(email)}&message=${encodeURIComponent(message)}`);
  });
  
