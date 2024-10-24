import './App.css'
import Form from './components/Form/Form';
import { GRAPHIC_URL } from "./constants";

function App() {
    return (
        <div className='App'>
            <div className="container">
                <img src={GRAPHIC_URL} alt="digital_payment Graphic" />
                <Form />
            </div>
        </div>
    )
}

export default App