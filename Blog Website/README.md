# CuratedClicks Blog Website

CuratedClicks is a responsive and modern blog website built using React. It features a customizable light/dark theme, a dynamic blog post listing, and an intuitive user interface. The website is fully responsive and mobile-friendly, ensuring a seamless experience on all devices.
# Demo Video
[![Demo Video](https://img.youtube.com/vi/3g-1Oeyyaeo/0.jpg)](https://youtu.be/3g-1Oeyyaeo)

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Customization](#customization)
- [Screenshots](#screenshots)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)

## Features
- **Responsive Design**: Adjusts to any screen size (desktop, tablet, mobile).
- **Theme Toggle**: Switch between light and dark modes with a single click.
- **Dynamic Blog Post Listing**: Fetch and display blog posts.
- **Scroll to Top Button**: Automatically appears when scrolling down and hides when at the top.
- **Contact Form**: A fully functional contact form, styled for both light and dark modes.
- **Sticky Navbar**: Navigation bar that stays at the top while scrolling.
- **Mobile-Friendly Navigation**: Hamburger menu for small screens that expands to show the navigation links.

## Project Structure
```bash
/src
  /components
    About.js            // About page component
    BlogList.js         // Blog list component
    BlogPost.js         // Single blog post component
    Contact.js          // Contact form component
    Footer.js           // Footer component
    HeroSection.js      // Hero section component
    Navbar.js           // Navbar with theme toggle and menu
    ScrollToTopButton.js // Scroll to top button
  /styles
    index.css           // Global styles
    Navbar.css          // Styles for Navbar
    contact.css         // Styles for Contact page
  App.js                // Main app component
  index.js              // Entry point of the application
```

## Installation

1. **Clone the repository**:

```bash
   git clone https://github.com/yourusername/curatedclicks-blog.git
   cd curatedclicks-blog
```
2. Install dependencies: Ensure that you have Node.js and npm installed. Then, install the required packages:

```bash
npm install
```
3. Run the development server:

```bash
npm start
```
4. Open your browser: Navigate to `http://localhost:3000` to view the site.

## Usage

- **View Blog Posts**: The home page features a dynamic blog post listing. Clicking on any blog post will navigate to the detailed blog page.

- **Navigate**: Use the navigation bar to go to the About or Contact pages. On smaller screens, the hamburger menu will allow you to toggle navigation links.

- **Toggle Theme**: Click the sun/moon icon in the navbar to toggle between light and dark themes. Your preference is saved and will persist on future visits.

- **Scroll to Top**: When you scroll down, a button will appear at the bottom-right corner, allowing you to scroll back to the top smoothly.

- **Contact Form**: On the contact page, you can fill out and submit the form.

## Customization

- **Blog Posts**: Blog posts are currently stored as JavaScript objects in `BlogList.js`. You can replace or extend this with dynamic data from a backend or CMS.

- **Styling**: All styling is modularized into CSS files under `src/styles`. Customize colors, fonts, and layouts as per your design needs.

- **Hero Section**: Update the `HeroSection.js` file to reflect your site's branding and content.

## Screenshots

- **Light Mode**
  ![Screenshot from 2024-10-18 17-02-56](https://github.com/user-attachments/assets/ce925914-a7aa-486f-b97d-8b82bb1d8f31)


- **Dark Mode**
  ![Screenshot from 2024-10-18 17-02-37](https://github.com/user-attachments/assets/e5a50f96-a19d-424b-8a74-b85397ef5c07)


- **Mobile View**
  ![menu](https://github.com/user-attachments/assets/20f09e30-9d2d-49f8-8bfe-31cf31daefde)

- 

## Technologies Used

- **React**: Frontend library for building user interfaces.
- **React Router**: For navigation between pages.
- **FontAwesome**: For icons in the navbar and theme toggle.
- **CSS**: For styling, with a focus on responsiveness.
- **Netlify**: For deployment (optional).

## Contributing

Contributions are welcome! If you'd like to contribute, follow these steps:

1. Fork the repository.
2. Create a new branch:

```bash
git checkout -b feature-branch-name
```
3. Make your changes and commit them:

```bash
git commit -m "Describe your changes"
```

4. Push to the branch:

```bash
git push origin feature-branch-name
```
5. Submit a pull request.


## License

This project is licensed under the MIT License. See the LICENSE file for details.
