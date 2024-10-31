import React from 'react';
import './About.css'; // Add some styling for the About page

const About = () => {
  return (
    <div className="about-container">
      <h1>About Me</h1>
      <p>
        Hi, I’m <strong>Atul Rajput</strong>, a passionate Web Developer and tech enthusiast with a strong interest in AI and front-end development. Currently pursuing my BTech in Electronics and Computer Science, I have a knack for designing user-friendly websites and bringing creative ideas to life through code.
      </p>
      
      <h2>Skills & Expertise</h2>
      <p>
        Over the years, I've worked with various technologies to build web applications and improve my development skills. Here are some of the key skills I specialize in:
      </p>
      <ul>
        <li>Front-end Development: HTML, CSS, JavaScript, React.js</li>
        <li>Back-end Development: Python, Django</li>
        <li>Version Control: Git, GitHub</li>
        <li>UI/UX Design</li>
        <li>Responsive Web Design</li>
        <li>Cloud Deployment: Netlify, Heroku</li>
      </ul>

      <h2>My Journey</h2>
      <p>
        My journey as a web developer started when I began experimenting with HTML and CSS in high school. Since then, I’ve been constantly learning and improving. I’ve contributed to open-source projects like Hacktoberfest, built personal web projects, and actively participated in tech challenges like the L'Oréal Sustainability Challenge.
      </p>
      
      <h2>Current Projects</h2>
      <p>
        I am currently working on an AI-driven microloan system that predicts financial reliability using machine learning. I'm also working on a React-based blog called "CuratedClicks" where I share insights about tech, development, and my coding experiences.
      </p>

      <h2>Get in Touch</h2>
      <p>
        Feel free to connect with me on <a href="https://www.linkedin.com" target="_blank" rel="noopener noreferrer">LinkedIn</a> or check out my work on <a href="https://github.com" target="_blank" rel="noopener noreferrer">GitHub</a>. Let’s build something great together!
      </p>
    </div>
  );
};

export default About;
