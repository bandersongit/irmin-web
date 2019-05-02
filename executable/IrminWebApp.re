open IrminWeb;
print_endline("Hello! irmin web app");

let x = LocalStorage.make();
LocalStorage.set(x, "adam", "weis");
let valOpt =
  switch (LocalStorage.get(x, "adam")) {
  | None => ""
  | Some(s) => s
  };
print_endline(valOpt);
let valOpt =
  switch (LocalStorage.get(x, "aweis")) {
  | None => ""
  | Some(s) => s
  };
print_endline(valOpt);

LocalStorage.remove(x, "adam");
let valOpt =
  switch (LocalStorage.get(x, "adam")) {
  | None => ""
  | Some(s) => s
  };
print_endline(valOpt);

let foo =
  LocalStorage.watch(x, ~prefix="adam", (k, v) =>
    switch (v) {
    | None => print_endline("no value for key = " ++ k)
    | Some(s) => print_endline("key = " ++ k ++ " value = " ++ s)
    }
  );
log(0.1);
module Mem_store = Irmin_mem.KV(Irmin.Contents.String);

let config = Irmin_mem.config();

let repo = Mem_store.Repo.v(config);

open Lwt.Infix;

let master = config => Mem_store.Repo.v(config) >>= Mem_store.master;

print_endline(Irmin.version);
