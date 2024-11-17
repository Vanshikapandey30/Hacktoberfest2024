document.getElementById('usernameForm').addEventListener('submit', function (e) {
    e.preventDefault();
    
    const name = document.getElementById('name').value.trim();
    const birthYear = document.getElementById('birthYear').value;

    if (name && birthYear) {
        const usernames = generateUsernames(name, birthYear);
        const usernameList = document.getElementById('generatedUsernames');
        usernameList.innerHTML = ''; // Clear previous results

        // Create divs for each username and add to the list
        usernames.forEach(username => {
            const div = document.createElement('div');
            div.textContent = username; // No '@gmail.com' suffix
            usernameList.appendChild(div);
        });
        
        document.querySelector('.result').style.display = '';
    }
});

function generateUsernames(name, birthYear) {
    const nameParts = name.split(' ');
    const firstName = nameParts[0].toLowerCase();
    const lastName = nameParts.length > 1 ? nameParts[1].toLowerCase() : '';

    const usernames = [];

    for (let i = 0; i < 6; i++) { // Generate 6 usernames
        // Randomly decide whether to add '.' or '_' or both
        const separator = Math.random() < 0.5 ? '.' : (Math.random() < 0.5 ? '_' : '');
        
        // Randomly decide whether to add birthYear at the end
        const addBirthYearAtEnd = Math.random() < 0.5;

        // Generate the base username
        let username = `${firstName}${separator}${lastName}`;

        // Add random numbers to avoid duplicates
        const randomNumber = Math.floor(Math.random() * 100);
        username += randomNumber;
        
        // Optionally add birthYear at the end
        if (addBirthYearAtEnd) {
            username += birthYear;
        } else {
            username += randomNumber; // If not adding birthYear, append random number
        }

        usernames.push(username);
    }

    return usernames;
}

// Optional: Fetch random user data from the Random User API
fetch('https://randomuser.me/api/')
    .then(response => response.json())
    .then(data => {
        const user = data.results[0];
        document.getElementById('name').value = `${user.name.first} ${user.name.last}`;
        document.getElementById('birthYear').value = new Date(user.dob.date).getFullYear();
    });
