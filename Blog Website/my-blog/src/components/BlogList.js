import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom'; // Import Link from react-router-dom
import postsData from '../data/posts'; // Import the posts from the JS file

const BlogList = () => {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    // Load the posts from the JS object
    setPosts(postsData);
  }, []);

  // Function to calculate reading time
  const calculateReadingTime = (text) => {
    const wordsPerMinute = 200; // Average reading speed
    const words = text.split(/\s+/).length; // Split the text into words
    const minutes = Math.ceil(words / wordsPerMinute); // Calculate minutes
    return minutes === 1 ? `${minutes} minute` : `${minutes} minutes`; // Return plural or singular
  };

  return (
    <div className="blog-list"> {/* Add the class here for styling */}
      <h1>Blog Posts</h1>
      {Array.isArray(posts) && posts.length > 0 ? (
        posts.map(post => (
          <Link to={`/post/${post.id}`} key={post.id} className="blog-post"> {/* Make the entire post clickable */}
            <div className="blog-content"> {/* Wrap content in a div */}
              <h2>{post.title}</h2>
              <p>{calculateReadingTime(post.body)} read</p> {/* Display reading time */}
              <p>{post.body.slice(0, 100)}...</p> {/* Show a snippet of the post */}
              <span className="read-more">Read More</span> {/* Styled read more button */}
            </div>
            <img src={post.image} alt={post.title} className="blog-image" /> {/* Display the image */}
          </Link>
        ))
      ) : (
        <p>No posts available</p>
      )}
    </div>
  );
};

export default BlogList;
