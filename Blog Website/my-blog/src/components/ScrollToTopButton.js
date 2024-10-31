import React, { useState, useEffect } from 'react';
import './ScrollToTopButton.css'; // Import CSS for styling

const ScrollToTopButton = () => {
  const [isVisible, setIsVisible] = useState(false);

  // Show button when page is scrolled down
  const toggleVisibility = () => {
    if (window.pageYOffset > 300) {
      setIsVisible(true);
    } else {
      setIsVisible(false);
    }
  };

  // Scroll the page to the top
  const scrollToTop = () => {
    window.scrollTo({
      top: 0,
      behavior: 'smooth', // Smooth scrolling
    });
  };

  useEffect(() => {
    window.addEventListener('scroll', toggleVisibility);
    return () => {
      window.removeEventListener('scroll', toggleVisibility);
    };
  }, []);

  return (
    <div>
      {isVisible && (
        <button className="scroll-to-top-btn" onClick={scrollToTop}>
          <i className="fa-solid fa-chevron-up"></i> {/* Chevron Up Icon */}
        </button>
      )}
    </div>
  );
};

export default ScrollToTopButton;
