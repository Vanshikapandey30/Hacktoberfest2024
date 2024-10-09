export default function Info3({info}) {
  return (
    <>
      <div className="box3">
        <div className="Box3Desc">
          <h1 className="weatherhead">Weather Description</h1>
            <p className="weatherdesc">
              The Weather can be described as {info.description} and it feels like {info.feels_like}&deg;C
            </p>
        </div>
          <div className="Box3Img">
            <img src="https://plus.unsplash.com/premium_photo-1661919210043-fd847a58522d?q=80&w=2071&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D" alt="" />
          </div>
      </div>
    </>
  );
}
