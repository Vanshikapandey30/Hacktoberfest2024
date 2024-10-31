import React from 'react';
import { useParams } from 'react-router-dom';
import postsData from '../data/posts'; // Import your local posts data
import './BlogPost.css'; // Adjust the path as necessary

const BlogPost = () => {
  const { id } = useParams(); // Get the post id from the URL parameters
  const post = postsData.find(post => post.id === parseInt(id)); // Find the post based on the id

  if (!post) {
    return <h2>Post not found</h2>; // Handle the case if no post is found with the given id
  }

  const calculateReadingTime = (text) => {
    const wordsPerMinute = 200; // Average reading speed
    const words = text.split(/\s+/).length; // Split the text into words
    const minutes = Math.ceil(words / wordsPerMinute); // Calculate minutes
    return minutes === 1 ? `${minutes} minute` : `${minutes} minutes`; // Return plural or singular
  };

  const readingTime = calculateReadingTime(post.body); // Get reading time

  return (
    <div className="blog-post-container"> {/* Use the updated class for styling */}
      <h2>{post.title}</h2>
      <p>{readingTime} read</p> {/* Display reading time */}
      <p><strong>Author:</strong> {post.author}</p>
      <img src={post.image} alt={post.title} className="blog-image" /> {/* Add the image */}
      <p>{post.body}</p> {/* Post content */}
    </div>
  );
};

export default BlogPost;
