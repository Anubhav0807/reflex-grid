import express from "express";
import dotenv from "dotenv";
import cors from "cors";

dotenv.config();

const app = express();
const PORT = process.env.PORT || 5000;

app.use(express.json());
app.use(cors());

app.get("/", (request, response) => {
  return response.status(200).json({
    success: true,
    message: "API is running",
    service: "Reflex Grid Backend",
    version: "1.0.0",
    authors: ["Anubhav Jha", "Shivansh Ranjan"],
    timestamp: new Date().toISOString(),
  });
});

app.get("/api/session-results", (request, response) => {
  const { range } = request.query;
  if (range == null) range = 10;

  return response.status(200).json({
    success: true,
    message: "Successfully retrived the session results",
    data: [],
  });
});

app.get("/api/session-duration", (request, response) => {
  return response.status(200).json({
    success: true,
    message: "Successfully retrived the session duration",
    duration: 30,
  });
});

app.post("/api/save-session-result", (request, response) => {
  const { score, avgResponseTime, responseTime } = request.body;
  console.log(request.body);

  return response.status(201).json({
    success: true,
    message: "Successfully saved the session result",
  });
});

app.listen(PORT, () => {
  console.log(`Server is running at port ${PORT}`);
});
