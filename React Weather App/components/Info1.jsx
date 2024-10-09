export default function Info1({info}) {
  let imgNum = 1;
  let humidityPercentage = 0;
  if(info.humidity>90){
    humidityPercentage = "100%";
  }else if(info.humidity>80 && info.humidity<90){
    humidityPercentage = "89%";
  }else if(info.humidity>50 && info.humidity<80){
    humidityPercentage = "67%";
  }else if(info.humidity>30 && info.humidity<50){
    humidityPercentage = "39%";
  }else if(info.humidity>10 && info.humidity<30){
    humidityPercentage = "10%";
  }else{
    humidityPercentage = "5%";
  }

  if(info.weatherImg === 'clear sky'){
    imgNum = 1;
  }else if(info.weatherImg === 'few clouds'){
    imgNum = 2;
  }else if(info.weatherImg === 'scattered clouds'){
    imgNum = 4;
  }else if(info.weatherImg === 'Clouds'){
    imgNum = 4;
  }else if(info.weatherImg === 'broken clouds'){
    imgNum = 4;
  }else if(info.weatherImg === 'shower rain'){
    imgNum = 5;           
  }else if(info.weatherImg === 'rain'){
    imgNum = 3;
  }else if(info.weatherImg === 'thunderstorm'){
    imgNum = 6;
  }else if(info.weatherImg === 'snow'){
    imgNum = 9;
  }else if(info.weatherImg === 'mist'){
    imgNum = 1;
  }

  return (
    <>
      <div className="Box1">
        <div className="Box1text">
          <div>
            <h1>{info.name}</h1>
            <p>Rain prediction: {humidityPercentage}</p>
          </div>
          <div>
            <h2>{Math.floor(info.temp)}&deg;</h2>
          </div>
        </div>
        <div className="Box1image">
          <img src={`../public/images/${imgNum}.png`} />
        </div>
      </div>
    </>
  );
}
