import React, { useState } from 'react';
import { BANK_UPI_DATA } from '../../constants';
import "./form.css"

function Form() {

    //create states for upi id
    const [upiId, setUpiId] = useState("");

    //lets create states for suggested values
    const [suggestion, setSuggestion] = useState("");

    //lets create states for list
    const [suggestionlist, setSuggestionList] = useState([]);

    const handleUpiIdChange = (e) => {
        //grab target from event obj
        const { target: { value = "" } } = e;

        //upi has a signature of VPA@BANK
        //we have to seperate VPA BANK
        const [users_vpa, bank_name] = value.split('@');


        //setUpiId
        setUpiId(value);

        //case:1 if there is no `@` sign suggestionlist should not listdown.
        if (!value || !value.includes(`@`)) {
            setSuggestion("");
            setSuggestionList([]);
            return;
        }

        //case:2 if there is no users_vpa suggestionlist should not listdown.
        if (!users_vpa) return;

        //we want to filter out bank name
        const bankRegex = new RegExp(`${bank_name}`);

        //look into the array and filterout data
        const matched_data = BANK_UPI_DATA.filter((bank) => {
            return bankRegex.test(bank)
        })

        //get the best suggested value from our matched_data
        let first_suggestion = matched_data[0];


        //case 3: if there is no bank name found return 
        if (bank_name && !matched_data.length) {
            first_suggestion = ""
        }

        //setting our suggestion list
        setSuggestion(`${users_vpa}@${first_suggestion}`);

        setSuggestionList(matched_data);

    }

    const handleKeyPressDown = (e) => {
        const { which = -1, keyCode = -1, code = "" } = e;
        const isRightArrowClick =
            which === 39 || keyCode === 39 || code.toLowerCase() === "arrowright";

        if (isRightArrowClick) {
            setUpiId(suggestion);
            setSuggestionList([]);
        }
    };

    // for list naviagtion read :
    //https://whereisthemouse.com/create-a-list-component-with-keyboard-navigation-in-react

    return (
        <form className='form_container'>
            <div className="input-wrapper">
                <input
                    id='input-box'
                    type="text"
                    pattern='.+@.+'
                    placeholder='Enter your UPI id'
                    autoCapitalize='off'
                    autoComplete="off"
                    spellCheck="off"
                    value={upiId}
                    onChange={handleUpiIdChange}
                    onKeyDown={handleKeyPressDown}
                />
                <input
                    id='input-box'
                    type="text"
                    value={suggestion}
                    onChange={handleUpiIdChange}
                    onKeyDown={handleKeyPressDown}
                />
            </div>
            <span className="line"></span>
            <button className='btn'>Pay Now</button>
            {
                suggestionlist.length ? (
                    <ul>
                        {
                            suggestionlist.map((bank) => {
                                return (<li key={bank}>{'@' + bank}</li>)
                            })
                        }
                    </ul>
                ) : null
            }
        </form>
    );
}

export default Form;