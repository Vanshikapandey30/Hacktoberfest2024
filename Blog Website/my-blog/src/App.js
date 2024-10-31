import React, { useState, useEffect } from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import BlogList from './components/BlogList';
import BlogPost from './components/BlogPost';
import Navbar from './components/Navbar';
import Footer from './components/Footer'; 
import HeroSection from './components/HeroSection'; 
import About from './components/About'; // Import About component
import Contact from './components/Contact'; // Import Contact component
import ScrollToTopButton from './components/ScrollToTopButton'; // Import ScrollToTopButton
import './index.css';

const App = () => {
  const [theme, setTheme] = useState('light-mode'); // Default theme

  // Load the saved theme preference from local storage
  useEffect(() => {
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme) {
      setTheme(savedTheme);
      document.body.classList.add(savedTheme); // Apply saved theme to body
    }
  }, []);

  // Function to toggle the theme
  const toggleTheme = () => {
    const newTheme = theme === 'dark-mode' ? 'light-mode' : 'dark-mode';
    setTheme(newTheme);
    document.body.classList.toggle('dark-mode', newTheme === 'dark-mode');
    localStorage.setItem('theme', newTheme); // Save the new theme preference
  };

  return (
    <Router>
      <div>
        <Navbar toggleTheme={toggleTheme} theme={theme} /> {/* Pass toggle function and current theme */}
        <Routes>
          <Route
            path="/"
            element={
              <>
                <HeroSection /> {/* Add the HeroSection on the home page */}
                <BlogList /> {/* Blog list will follow after hero section */}
              </>
            }
          />
          <Route path="/post/:id" element={<BlogPost />} />
          <Route path="/about" element={<About />} />
          <Route path="/contact" element={<Contact />} />
        </Routes>
        <Footer /> {/* Add the footer at the bottom */}
        <ScrollToTopButton /> {/* Add Scroll to Top button */}
      </div>
    </Router>
  );
};

export default App;
