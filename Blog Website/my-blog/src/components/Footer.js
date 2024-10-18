import React from 'react';
import './Footer.css'; // You'll create this CSS file for styling the footer

const Footer = () => {
  return (
    <footer className="footer">
      <div className="footer-content">
        <p>&copy; {new Date().getFullYear()} My Blog. All rights reserved.</p>
        <p>
          Follow us on:
          <a href="https://twitter.com" target="_blank" rel="noopener noreferrer"> Twitter</a> |
          <a href="https://facebook.com" target="_blank" rel="noopener noreferrer"> Facebook</a> |
          <a href="https://instagram.com" target="_blank" rel="noopener noreferrer"> Instagram</a>
        </p>
      </div>
    </footer>
  );
};

export default Footer;
