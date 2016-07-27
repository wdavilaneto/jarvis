create table activation_function (
    id integer primary key,
    name text not null
);

create table neural_network (
    id integer PRIMARY KEY,
    name text not null ,
    num_layers integer not null,
    num_input integer not null ,
    num_hidden integer not null ,
    num_output integer not null,
    desired_error numeric not null,
    max_epochs integer ,
    epochs_between_reports integer,
    activation_hidden integer REFERENCES activation_function(id) ,
    activation_output integer  REFERENCES activation_function(id)

);

create table corpus {
    id integer PRIMARY KEY,



};

ALTER TABLE neural_network ADD trained text;

commit;