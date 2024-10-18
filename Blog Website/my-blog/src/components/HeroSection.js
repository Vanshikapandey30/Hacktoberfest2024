import React from 'react';
import './HeroSection.css';

const HeroSection = () => {
  return (
    <div className="hero-container">
      <div className="hero-image"></div> {/* Background image from CSS */}
      <div className="hero-overlay"></div> {/* Overlay for transparency effect */}
      <div className="hero-text">
        <h1>Welcome to My Blog</h1>
        <p>Your daily dose of tech insights</p>
      </div>
    </div>
  );
};

export default HeroSection;
