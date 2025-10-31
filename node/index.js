const express = require("express");
const cors = require("cors");
const calculator = require("./build/Release/calculator");

const app = express();
app.use(cors());
app.use(express.json());

const PORT = process.env.PORT || 3001; // run on 3001, separate from React

app.get("/calculate", (req, res) => {
  const { num1, op, num2 } = req.query;

  if (!num1 || !op || !num2) {
    return res.status(400).json({ error: "Missing parameters" });
  }

  const result = calculator.performOperation(parseFloat(num1), op, parseFloat(num2));
  res.json({ result });
});

app.listen(PORT, () => {
  console.log(`✅ API running on http://localhost:${PORT}`);
});
