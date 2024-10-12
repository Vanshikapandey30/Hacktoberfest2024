import React, { useState } from 'react';
import './App.css'; // CSS file for styling

const Calculator = () => {
  const [input, setInput] = useState('');
  const [result, setResult] = useState('');

  // Function to handle button clicks
  const handleButtonClick = (value) => {
    setInput(input + value);
  };

  // Function to evaluate the expression
  const evaluateExpression = () => {
    try {
      const result = eval(input);
      setResult(result.toString());
    } catch (error) {
      setResult('Error');
    }
  };

  // Function to clear the input and result
  const clearInput = () => {
    setInput('');
    setResult('');
  };

  return (
    <div className="calculator">
      <h1>React Calculator</h1>
      <input type="text" value={input} readOnly />
      {result && <div className="result">{result}</div>}
      <div className="buttons">
        {[7, 8, 9, '+', 4, 5, 6, '-', 1, 2, 3, '*', 'C', 0, '=', '/'].map((item, index) => (
          <button key={index} onClick={() => {
            if (item === '=') {
              evaluateExpression();
            } else if (item === 'C') {
              clearInput();
            } else {
              handleButtonClick(item);
            }
          }}>
            {item}
          </button>
        ))}
      </div>
    </div>
  );
};

export default Calculator;
