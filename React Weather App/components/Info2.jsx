import DeviceThermostatIcon from "@mui/icons-material/DeviceThermostat";
import CompareArrowsIcon from "@mui/icons-material/CompareArrows";
import InvertColorsIcon from "@mui/icons-material/InvertColors";
import AirIcon from "@mui/icons-material/Air";

export default function Info2({info}) {
  return (
    <>
      <div className="Box2">
        <div className="Box2head">
          <h1>Weather Info</h1>
        </div>
        <div className="Box2cards">
          <div className="cardsCont">
            <div>
              <h1>
                <DeviceThermostatIcon />
                Max Temp
              </h1>
              <h2>{info.temp_max}&deg;</h2>
            </div>
            <div>
              <h1>
                <CompareArrowsIcon />
                Pressure
              </h1>
              <h2>{info.pressure}</h2>
            </div>
          </div>
          <div className="cardsCont">
            <div>
              <h1>
                <InvertColorsIcon />
                Humidity
              </h1>
              <h2>{info.humidity}</h2>
            </div>
            <div>
              <h1>
                <AirIcon />
                Wind Speed
              </h1>
              <h2>{info.speed} km/h</h2>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}