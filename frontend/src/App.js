import React, { useState } from "react";
import "./App.css";

function App() {
  const [num1, setNum1] = useState("");
  const [num2, setNum2] = useState("");
  const [op, setOp] = useState("+");
  const [result, setResult] = useState(null);
  const [error, setError] = useState("");

  const calculate = async () => {
    try {
      // Build correct API URL for Codespaces or localhost
      const apiUrl =
        process.env.REACT_APP_API_URL ||
        `https://${window.location.hostname.replace("-3000", "-3001")}`;

      // ✅ Encode operator so '+' isn’t lost
      const encodedOp = encodeURIComponent(op);

      const response = await fetch(
        `${apiUrl}/calculate?num1=${num1}&op=${encodedOp}&num2=${num2}`
      );

      if (!response.ok) {
        throw new Error("Failed to connect to API");
      }

      const data = await response.json();

      if (data.error) {
        throw new Error(data.error);
      }

      setResult(data.result);
      setError("");
    } catch (err) {
      console.error(err);
      setError("Error: Unable to calculate. Check API connection or input.");
      setResult(null);
    }
  };

  return (
    <div className="App">
      <h1>Simple C++ Calculator (via Node API)</h1>
      <div className="calc-container">
        <input
          type="number"
          value={num1}
          onChange={(e) => setNum1(e.target.value)}
          placeholder="First number"
        />
        <select value={op} onChange={(e) => setOp(e.target.value)}>
          <option value="+">+</option>
          <option value="-">-</option>
        </select>
        <input
          type="number"
          value={num2}
          onChange={(e) => setNum2(e.target.value)}
          placeholder="Second number"
        />
        <button onClick={calculate}>Calculate</button>
      </div>

      {result !== null && (
        <h2>
          Result: <span>{result}</span>
        </h2>
      )}

      {error && <p style={{ color: "red" }}>{error}</p>}
    </div>
  );
}

export default App;
