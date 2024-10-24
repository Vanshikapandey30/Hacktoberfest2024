import { useState,useEffect } from "react"
import { useRef } from "react";

export default function Body(){
   
    const searchInput = useRef(null);
    let handleSearch= (e)=>{
        e.preventDefault();
        console.log(searchInput.current.value);
        setPageNum(1);
        showImages();
        searchInput.current.value="";
    }
    let handleChange=(option)=>{
      searchInput.current.value= option;
        console.log(searchInput.current.value);
        setPageNum(1);
        showImages();
    }    
    
     let [images, setImages]= useState([]);
     let [pagesTotal, setPagesTotal]= useState(0);
     let [pageNum, setPageNum]= useState(1);

     useEffect(()=>{
      showImages();
  },[pageNum]);

     let key="pigfTYNFJ-J6Opm4NUUQ92z-jmEDCg_7OLwdo1IfZnQ";
     let URL= 'https://api.unsplash.com/search/photos';
     let imgNo= 15;
     let showImages = async () => {
        try {
          let response = await fetch(`${URL}?query=${searchInput.current.value}&page=${pageNum}&per_page=${imgNo}
            &client_id=${key}`);
          let data = await response.json();
          console.log( data);
          setImages(data.results);
        setPagesTotal(data.total_pages);
        } catch (error) {
          console.error("Error fetching data:", error);
        }
      };
      let prev=()=>{
         setPageNum(pageNum -1);
         console.log(pageNum);
      };let next=()=>{
        setPageNum(pageNum +1);
        console.log(pageNum);
     }
     
    return(
        <>
        <div className=" h-max w-full">
            <div className="search flex justify-center pt-20 ">
            <form onSubmit={handleSearch}><input placeholder="Search the image" type="search" className="
             w-[700px] h-12 rounded-md pl-3 font-medium border-2 border-black" ref={searchInput}/></form>
            </div>

            <div className="options flex justify-center mt-2 mx-12">
                <button onClick={()=>handleChange('Bird')} className=" w-32 border-black h-8 border-1 bg-blue-500 rounded-md  mr-1">Birds</button>
                <button onClick={()=>handleChange('Flower')}  className=" w-32 border-black h-8 border-1 bg-blue-500 rounded-md  mr-1">Flower</button>
                <button onClick={()=>handleChange('Nature')}  className=" w-32 border-black h-8 border-1 bg-blue-500 rounded-md  mr-1">Nature</button>
                <button onClick={()=>handleChange('sky')}  className=" w-32 border-black h-8 border-1 bg-blue-500 rounded-md  mr-1">sky</button>
            </div>

            <div className="mt-4 mx-12 h-[75%] rounded-lg p-2 ">
                <div className="flex flex-wrap mx-12">
                   {(images || []).map((image)=>(
                    <img src={image.urls.small}
                    key= {image.id} 
                    className="images h-[300px] w-[300px] m-4 rounded-md
                    hover:scale-110 hover:border-4 hover:border-lime-300 justify-center align-middle"/>
                 ))}
                </div>
            </div>
           <div className="flex justify-center align-middle mb-4">
            {pageNum>1 && <button className=" w-32 border-black h-8 border-1 bg-black text-white
             rounded-md mr-2" onClick={prev}>Previous</button>}
            {pageNum < pagesTotal && <button  className=" w-32 border-black h-8 border-1 mr-2
             bg-black text-white rounded-md" onClick={next}>Next</button>}
           </div>

        </div>
        </>
    )
}