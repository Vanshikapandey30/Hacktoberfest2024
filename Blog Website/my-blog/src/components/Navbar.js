import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import './Navbar.css'; // Make sure this file has the necessary CSS
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faSun, faMoon, faBars, faTimes } from '@fortawesome/free-solid-svg-icons';

const Navbar = ({ toggleTheme, theme }) => {
  const [isMenuOpen, setIsMenuOpen] = useState(false); // State to track menu visibility

  const toggleMenu = () => {
    setIsMenuOpen(!isMenuOpen); // Toggle the menu state between open and close
  };

  return (
    <nav className="navbar">
      <div className="navbar-brand">
        <Link to="/">My Blog</Link>
      </div>
      
      <button className="menu-toggle-btn" onClick={toggleMenu}>
        {/* Switch between hamburger and close icon based on menu state */}
        <FontAwesomeIcon icon={isMenuOpen ? faTimes : faBars} />
      </button>
      
      <ul className={`navbar-links ${isMenuOpen ? 'open' : ''}`}>
        <li>
          <Link to="/" onClick={toggleMenu}>Home</Link>
        </li>
        <li>
          <Link to="/about" onClick={toggleMenu}>About</Link>
        </li>
        <li>
          <Link to="/contact" onClick={toggleMenu}>Contact</Link>
        </li>
        <li>
          <button id="theme-toggle" className="theme-toggle-btn" onClick={toggleTheme}>
            {theme === 'dark-mode' ? (
              <FontAwesomeIcon icon={faSun} /> // Show sun icon for dark mode
            ) : (
              <FontAwesomeIcon icon={faMoon} /> // Show moon icon for light mode
            )}
          </button>
        </li>
      </ul>
    </nav>
  );
};

export default Navbar;
