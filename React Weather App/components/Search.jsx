import { useState } from "react";
import SearchIcon from "@mui/icons-material/Search";

export default function Search({ updateWeatherInfo }) {
  let [input, setInput] = useState("");
  let [error, setError] = useState(false);
  const API_URL = "https://api.openweathermap.org/data/2.5/weather";
  const API_KEY = "f7f9a634fa7072c50ac54cf7ccfe885f";

  let getWeatherInfo = async () => {
    try {
      let response = await fetch(
        `${API_URL}?q=${input}&appid=${API_KEY}&units=metric`
      );
      let jsonResponse = await response.json();
      let result = {
        name: jsonResponse.name,
        temp: jsonResponse.main.temp,
        temp_max: jsonResponse.main.temp_max,
        pressure: jsonResponse.main.pressure,
        humidity: jsonResponse.main.humidity,
        speed: jsonResponse.wind.speed,
        feels_like: jsonResponse.main.feels_like,
        description: jsonResponse.weather[0].description,
        weatherImg: jsonResponse.weather[0].main,
      };
      return result;
    } catch (err) {
      throw err;
    }
  };

  let searchInput = (e) => {
    setInput(e.target.value);
  };

  let handleSubmit = async () => {
    try {
      setInput("");
      let info = await getWeatherInfo();
      await updateWeatherInfo(info);
    } catch (err) {
      setError(true);
    }
  };
  return (
    <>
      <input
        onChange={searchInput}
        value={input}
        placeholder={error ? "No such place found" : "Search for cities"}
        className='searchInput'
      />
      <div className='searchBtn' onClick={handleSubmit}>
        <SearchIcon className="SearchIcon" />
      </div>
    </>
  );
}
