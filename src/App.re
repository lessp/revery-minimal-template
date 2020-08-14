open Revery;
open Revery.UI;

let init = app => {
  let window =
    App.createWindow(
      app,
      "Our window title",
      ~createOptions=WindowCreateOptions.create(~width=512, ~height=384, ()),
    );

  let _update = UI.start(window, <Text text="Hello DEV.to-readers!" />);

  ();
};

App.start(init);
