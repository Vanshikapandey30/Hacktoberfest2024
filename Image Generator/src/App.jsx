import { PlaceholdersAndVanishInput } from "./components/ui/placeholders-and-vanish-input";
import { WavyBackground } from "./components/ui/wavy-background";
import { CardBody, CardContainer, CardItem } from "./components/ui/3d-card";
import { useState } from "react";
function App() {
   const [prompt, setprompt] = useState("");

  const handleChange = (e) => {
    setprompt(e.target.value);
    
  };

  const onSubmit = (e) => {
     
    e.preventDefault();
    console.log("Submitted", prompt);


  };



  return (
    <>
      <div className="flex justify-center items-center h-[100vh] w-full">
        <WavyBackground className="flex flex-col justify-center items-center w-full max-w-4xl mx-auto h-full p-10  gap-6">
          <h3 className="text-3xl md:text-4xl lg:text-5xl text-white font-bold inter-var text-center mb-4">
            Welcome to AI Image Generator
          </h3>
          <div>
            <CardContainer className="inter-var">
              <CardBody className="bg-gray-800 relative group/card  dark:hover:shadow-2xl dark:hover:shadow-emerald-500/[0.1] dark:bg-black dark:border-white/[0.2] border-black/[0.1] w-auto sm:w-[30rem] h-auto rounded-xl p-8 border  ">
                <CardItem translateZ="100" className="w-full   mt-2">
                  <img
                    src=""
                    className="h-64 w-full object-cover rounded-xl group-hover:shadow-xl"
                  />
                </CardItem>
                <div className="flex justify-between items-center "></div>
              </CardBody>
            </CardContainer>
          </div>

          <div className="flex flex-col items-center justify-center   w-full">
            <div className="w-[80vw] md:w-[50vw]">
              <PlaceholdersAndVanishInput
                placeholders={["Enter the your prompt"]}
                onChange={handleChange}
                onSubmit={onSubmit}
              />
            </div>
          </div>
        </WavyBackground>
      </div>
    </>
  );
}

export default App;
