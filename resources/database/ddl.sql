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

ALTER TABLE neural_network ADD trained text;

create table corpus (
    id integer PRIMARY KEY,
    name text not null,
    language TEXT
);

create table stop_word  (
    language TEXT primary key not null,
    words text not null
);

create table document (
    uuid text primary key not null,
    corpus_id integer not null references corpus(corpus_id),
    ref_id integer UNIQUE,
    filterd_text text
);

create table keyword (
    stemmed TEXT primary key,
    language TEXT
);

create table word_document (
    uuid text REFERENCES document(uuid),
    keyword text references keyword(stemmed) ,
    count integer
);

create table word_form (
    word text primary key,
    keyword text references keyword(stemmed)
);





-- TODO STEM tabel and STEMMING TYPES (ADJ (ATION ITY MENT..)...)

commit;