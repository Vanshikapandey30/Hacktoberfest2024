import Search from "../components/Search";
import Logo from "../components/Logo";
import Info1 from "./Info1";
import Info2 from "./Info2";
import Info3 from "./Info3";
import { useState } from "react";
import './style.css'

function WeatherApp() {
  const [weatherInfo, setWeatherInfo] = useState({
    name: "Sydney",
    temp: 41.81,
    temp_max: 41.81,
    pressure: 989,
    humidity: 81,
    speed: 3.06,
    feels_like: 47.39,
    description: "broken clouds",
  });

  let updateWeatherInfo = (result) => {
    setWeatherInfo(result);
  };

  return (
    <>
      <div className='container'>
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

