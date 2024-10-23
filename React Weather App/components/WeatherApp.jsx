import Search from "../components/Search";
import Logo from "../components/Logo";
import Info1 from "./Info1";
import Info2 from "./Info2";
import Info3 from "./Info3";
import { useState, useEffect } from "react";
import "./style.css";

function WeatherApp() {
  const [weatherInfo, setWeatherInfo] = useState({
    name: "Loading...",
    temp: 0,
    temp_max: 0,
    pressure: 0,
    humidity: 0,
    speed: 0,
    feels_like: 0,
    description: "Loading...",
  });
  const fetchCityAndWeather = async () => {
    try {
      // Get the user's city from the IP address
      const API_URL = "https://ipinfo.io/json?token=7b69681b52ed9e";
      const response = await fetch(API_URL);
      const geoData = await response.json();
      const city = geoData.city;

      // Now fetch the weather data for that city
      const weatherApiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=c6e315d09197cec231495138183954bd&units=metric`;
      const weatherResponse = await fetch(weatherApiUrl);
      const weatherData = await weatherResponse.json();

      // Update the state with the fetched weather info
      setWeatherInfo({
        name: weatherData.name,
        temp: weatherData.main.temp,
        temp_max: weatherData.main.temp_max,
        pressure: weatherData.main.pressure,
        humidity: weatherData.main.humidity,
        speed: weatherData.wind.speed,
        feels_like: weatherData.main.feels_like,
        description: weatherData.weather[0].description,
      });
    } catch (error) {
      console.error("Error fetching weather data:", error);
      setWeatherInfo({
        ...weatherInfo,
        name: "Error",
        description: "Unable to fetch data",
      });
    }
  };
  let updateWeatherInfo = (result) => {
    setWeatherInfo(result);
  };
  useEffect(() => {
    fetchCityAndWeather();
  }, []);

  return (
    <>
      <div className="container">
        <div className="initials">Made by Dhruv Pal❤️</div>
        <div className="topCont">
          <Logo />
          <Search updateWeatherInfo={updateWeatherInfo} />
        </div>
        <div className="bodyCont">
          <Info1 info={weatherInfo} />
          <Info2 info={weatherInfo} />
          <Info3 info={weatherInfo} />
        </div>
      </div>
    </>
  );
}

export default WeatherApp;
