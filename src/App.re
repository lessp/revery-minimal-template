open Revery;
open Revery.UI;

module Cats = {
  let%component make = (~url, ()) => {
    let%hook (state, setState) = Hooks.state("");

    let%hook () =
      Hooks.effect(
        OnMountAndIf((a, b) => a != b, url),
        () => {
          Fetch.get(url)
          |> Lwt.map(
               fun
               | Ok({Fetch.Response.body, _}) =>
                 setState(_prevValue => Fetch.Body.toString(body))
               | Error(error) => {
                   Printf.printf("That's an error: %s", error);
                   setState(_prevValue => error);
                 },
             )
          |> ignore;

          None;
        },
      );

    <Text text=state />;
  };
};

let init = app => {
  let window =
    App.createWindow(
      app,
      "Our window title",
      ~createOptions=WindowCreateOptions.create(~width=512, ~height=384, ()),
    );

  let _startEventLoop = Revery_Lwt.startEventLoop(~name="loop", ());

  let _update = UI.start(window, <Cats url="https://catfact.ninja/fact" />);

  ();
};

App.start(init);
